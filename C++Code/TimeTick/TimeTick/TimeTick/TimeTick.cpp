// TimeTick.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "json.hpp"
#include <string>
#include <iostream>
using json = nlohmann::json;
using namespace std;

int main()
{
    //cin
    json j;
    j["mt"] = 1;
    j["mtno"] = "zhang";

    json jtmp;
    jtmp["speaker"] = j;

    j["mt2"] = "2";
    j["mtno"] = "li";
    jtmp["chairman"] = j;

    string str = jtmp.dump();

    cout << str << endl;

    //cout
    json jcout = json::parse(str.c_str());

    json jcouttmp = jcout["speaker"];

    cout << jcouttmp.dump() << endl;
    cout << jcouttmp["mt"] << endl;
    cout << jcouttmp["mtno"] << endl;
    string strcint = " { \"i\": \"172.16.179.144\", \"type\" : \"MCU_CM_SIMCONFINFO_NTF\", \"chairman\" : {\"mtchnid\": \"0\", \"mtidentify\" : {}, \"confE164\" : \"\", \"mttype\" :\"0\", \"calltype\" : \"0\", \"mtNO\" : \"\"}, \"confE164\" : \"6660609\", \"pid\" : \"168815\", \"speaker\" : {\"mtchnid\": \"0\", \"mtidentify\" : {\"mtid\": \"1\", \"mcuidx\" : \"\"}, \"confE164\" : \"\", \"mttype\" : \"3\", \"calltype\" : \"1\", \"mtNO\" : \"172.16.178.224\"} } ";

    json jsonin = json::parse(strcint.c_str());
    cout << jsonin.dump(4) << endl;
    //     if (!jsonin["i"].empty())
    //     {
    //     cout << "11111111111111111" << endl;
    //         cout << jsonin["i"].get<string>();
    //     }
    //     cout << "2222222222222" << endl;
    //      string strvalue =  jsonin.value("i", "11");
    //      cout << strvalue << endl;
    //     cout << jsonin.dump(4) << endl;
    /*cout << jsonin["hi"].get<string>() <<endl;*/
    /*    cout << str.c_str() << endl;*/
    if (!jsonin["hi"].empty())
    {
        cout << "11111111111111111" << endl;
        cout << jsonin.at("hi") << endl;
    }

    //cout << jcint << endl;
    cout << "end here" << endl;
    //     string s = "HelpY_123Share";
    //     char tmp[20] = { "HelpY_123Share" };
    //     converstr2up(s);
    //     convertmp2up(&tmp[0]);
    //     cout << s << endl;
    //     cout << tmp << endl;
    // 	kdv_netaddr i = 2;
    // 	kdv_netaddr j = 3;
    // 	printf("%s,%s\n", fun(i).c_str(), fun(j).c_str());
    // 	Init Ini;
    // 	cout << Ini.a << "\t"<< Ini.b<<endl;
    //
    // 	char tmp[20];
    // 	memset(tmp, 0,20);
    // 	conver(&tmp[0]);
    // 	cout << tmp<< "sss" << endl;
    //     Test ti;
    //     ti.ad = 1;
    //
    //     TestEx *tp = new TestEx;
    //     memcpy(tp, &ti, sizeof(ti));
    //     memcpy(tp->ach, "helloS", 20);
    //
    //     cout << tp->ad << tp->ap << endl;
    //     cout << sizeof(tp->ach) << endl;
    //
    //
    //
    // 	char str[20] = { 0 };
    // 	cout << strncmp(str, "", 20) << endl;

    /*
	int ip = -1;
	char tmp[60] = { 0 };
	cout << fun(ip).c_str() << endl;

	sprintf(tmp, "%s", fun(ip).c_str());

	cout << tmp << endl;

	cout << GetStrByNetAddr(ip).c_str() << endl;
	sprintf(tmp, "%s", GetStrByNetAddr(ip).c_str());

	cout << tmp << endl;

	memset(tmp, 0, sizeof(tmp));
	ip = htonl(ip);
	char *p = (char *)&ip;
	sprintf(tmp, "%d.%d.%d.%d%c", p[0], p[1], p[2], p[3], 0);
	cout << tmp << endl;
	*/

    //	char tmp[20];
    char i = 1;

    // 	memcpy(tmp, &i , sizeof(char));
    // 	memcpy(tmp+2, &i , sizeof(char));

    // 	sprintf(tmp, "%s", "127.0.0.1");
    // 	cout << tmp << endl;

    /*	string str = "123";*/
    /*	memcpy(tmp, str.c_str(), str.size());*/
    /*	cout << tmp << endl;*/

    // 	string str1 = "0.0.0.0";
    // 	cout << str1.c_str() << "\t111" << endl;
    //
    // 	char tmp[10] = "127.0.0.1";
    // 	char *p = tmp;
    // 	string str2 = p;
    // 	cout << str2.c_str() << endl;
    //
    //
    //     std::cout << "Hello World!\n";

    /*	char str[] = "127.0.0.1";*/
    //	kdv_netaddr netaddr;

    //	str2netaddr(str, 10, &netaddr);

    //	cout << netaddr << endl;

    // 	kdv_netaddr netaddr;
    // 	char str[10] = "h";
    // 	str2netaddr(str, 0, &netaddr);
    // 	cout << netaddr.addr << endl;
    // 	memcpy((char*)netaddr.addr, str,10);
    // 	cout << netaddr.addr << endl;
    //
    // 	kdv_netaddr netaddr2;
    // 	netaddr2 = netaddr;
    // 	int dw = strncmp(netaddr.addr,netaddr2.addr, KDV_MAX_IPADDR_STR_LEN) == 0;
    // 	cout << netaddr2.addr << "\t"<<  dw << endl;
    //
    // 	memcpy(netaddr.addr, "127.0.0.1", 10);
    // 	int len = strlen("127.0.0.1");
    // 	int ret = strcmp(netaddr.addr, "127.0.0.1");
    // 	cout << ret<< "\t" << len << endl;

    // 	CMD5Encrypt cMd5Enc;
    //
    // 	const char * pchTmp = "123456";
    // 	char tmp[25] = { 0 };
    // 	strncpy(tmp,pchTmp,25);
    // 	char achtmp[16] = { 0 };
    // 	cMd5Enc.GetEncrypted(tmp, achtmp, 16);
    //
    // 	cout << achtmp << endl;

    // 	MD5 test;
    // 	string a = "";
    // 	cout << "Plain Text: ";
    // 	getline(cin, a);
    // 	cout << "result: " << test.encode(a) << endl;

    //std::string src = "fasdfasdfasdfnmmw,enrsudfnsmndfejkjhuasdmnf";
    // 	string src = "123456";
    // 	Md5Encode encode_obj;
    // 	std::string ret = encode_obj.Encode(src);
    // 	std::cout << "info: " << src.c_str() << std::endl;
    // 	std::cout << "md5: " << ret.c_str() << std::endl;

    //界面输入

    //时间记录

    //数据保存

    //输出展示
    while (1)
    {
    }
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
