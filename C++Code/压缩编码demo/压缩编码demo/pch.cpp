// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"
#include "iostream"
#include "zlib/zlib.h"
#include "kdvtype.h"
// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
using namespace std;

void CompressAndEncodeData(const std::string& strInData, std::string& strOutData)
{
	u8 abyCompressMsg[1024 * 200 + 1] = { 0 };
	unsigned long dwCompressMsgLen = sizeof(abyCompressMsg);

}

void DecodeAndUnCompressData(const std::string& strInData, std::string& strOutData)
{

}