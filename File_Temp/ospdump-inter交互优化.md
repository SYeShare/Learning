

**cmu崩溃**

原因：静态打印ospdump获取inter侧数据，走的获取instance指针直接调用方式，此时inter侧对应数据也发生了改动，导致访问地址出错，导致崩溃；  涉及多线程安全问题；



流程处理：showconfpair(osp telnet获取命令)  --->   调用OspInstDump ---->  osp接口实现(获取appget()对应的inst，直接调用InstanceDump) ----> 调用print()接口。

波及影响：跨线程的打印信息都会有影响；(仅VC侧打印能保证数据安全，需要调整mtmgr、inter侧的静态打印接口)， 不再可以直接调用OspInstDump



**解决方案**：

1、Api主进程直接触发post发消息到mtmgr、interactssn、upussn、dsmgr、apssn、

​	尽量减少改动点 波及：

对ospintdump做重载

​		对vc处理仍沿用原先的接口

​		对跨线程的mtmgr  、 inter ……打印采用重载函数；

```c++
OSPEVENT(APP_APP_DUMPINFO_NTF,		EV_MCU_BGN + 1909);
void OspInstDump(u16 aid, u16 InstId, u32 param, BOOL32 bSendMsg);//重载
//void ConvertDumpInfoToMsg( u32 param,CServMsg &cSer); //转换消息体 zhijie fa
//void ConvertMsgToDumpInfo( u32 &param,CServMsg cSer);

void OspInstDump(u16 aid, u16 InstId, u32 param, BOOL32 bSendMsg) 
{
    if (bSendMsg)
    {
        CServMsg cSer;
        //ConvertDumpInfoToMsg( param, cSer); //整合信息
        OspPost(MAKEIID(aid, InstId), wEvent, cSer.GetMsgBody(), cSer.GetMsgBodyLen());
    }
}

void CInterActDirInst::InstanceEntry( CMessage * const pcMsg ){
    //判定wEvent，调用InstanceDump();
    ConvertMsgToDumpInfo(aid, InstId, param, cSer);
    InstanceDump(param);
}
```

改动点：调整接口，增加一条消息eventid；



















2、在现有逻辑不变的情况下，对非vc侧的InstanceDump 做改动，增加消息发到自身的InstanceEntry， 去调用InstanceDump。---显得多余；

​		









3、在vc侧实现OspInstDump的方法，改写逻辑 × 不可行

```c++
         void InstanceDump(u16 aid, u16 InstId, u32 param)
         {
             CApp *pcApp;
             int InstNum;
            u16  CurrInsNum;
             CInstance* pcInstance = NULL;
 
             pcApp = AppGet(aid);
             if (pcApp == NULL)
             {
                 OspPrintf(TRUE, FALSE, "this application is not exist!\n");
                 return;
             }
 
            InstNum = pcApp->GetInstanceNumber();
            if (InstId == CInstance::PENDING)   //显示所有的Instance信息
             {
                 for (CurrInsNum = 1; CurrInsNum <= InstNum; CurrInsNum++)
                 {
                     pcInstance = pcApp->GetInstance(CurrInsNum);
                     if (pcInstance != NULL)
                     {
                         pcInstance->InstanceEntry(param);
                    }
                 }
            }
```

影响： 波及osp接口---影响封装性