// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"
#include "iostream"
#include "zlib/zlib.h"
#include <stdio.h>
#include "kdvtype.h"
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。

void CopySomeThing(int dwnum)
{
	int *Array = new int[dwnum];

}

void TransArrayToCopy(MyStruct * pArrayContent)
{
	MyStruct abytemp[5];
	for (char i = 0; i < 5; i++)
	{
		abytemp[i].m_byNum = i;
	}

	memcpy(pArrayContent, abytemp, sizeof(MyStruct)*5);
	for (int i = 0; i<5 ;i++)
	{
		cout << "TransArrayToCopy():  array:" << pArrayContent[i].m_byNum << endl;
	}

}

// BOOL32 CompressAndEncodeData(const std::string& strInData, std::string& strOutData)
// {
// 	u8 abyCompressMsg[1024 * 200 + 1] = { 0 };
// 	unsigned long dwCompressMsgLen = sizeof(abyCompressMsg);
// 	const s32 nErrCode = compress((Bytef*)abyCompressMsg, (uLongf*)&dwCompressMsgLen,
// 		(const Bytef*)strInData.c_str(), strInData.length());
// 	if (nErrCode != 0)
// 	{
// 		printf( "[%s]compress msg err, errcode:%d\n",
// 			__FUNCTION__, nErrCode);
// 		return FALSE;
// 	}
// 	return TRUE;
// 
// }
// 
// void DecodeAndUnCompressData(const std::string& strInData, std::string& strOutData)
// {
// 
// }