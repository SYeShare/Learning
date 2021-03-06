// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

#ifndef PCH_H
#define PCH_H
#include "kdvnetaddr.h"
#include <iostream>
#include <string>
// TODO: 添加要在此处预编译的标头
using namespace std;

void OperatorCommond();

void TimeRun();

void DataSaved();

void TimeDataShow();

inline std::string GetStrByNetAddr(kdv_netaddr netAddr) //传主机序
{
	std::string strIp = KDV_NET_ANYADDR;

	netAddr = htonl(netAddr);

	char *pNet = netaddr2str(&netAddr);
	if (pNet != NULL)
	{
		strIp = pNet;
	}
	return strIp;
}

class cNetAddr
{
private:
    kdv_netaddr netAddr;
public:
    void setIp(kdv_netaddr nTmp) { netAddr = nTmp; }
    kdv_netaddr getIp(void) const { return netAddr; }
};

struct Test
{
    int ad;
};
struct TestEx :public Test
{
    int ap;
    char ach[20];

    char* getach() { return ach; }
};
string fun(kdv_netaddr dwId) {
    /*char str[10] = { 0 };*/
    string str;
    dwId = htonl(dwId);
    str = netaddr2str(&dwId);

    return str;
}

void conver(char*p)
{
    memcpy(p, "hello", 1);
}

string converstr2up(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

void convertmp2up(char*p)
{
    for (int i = 0; i < strlen(p); i++)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p = *p - 32;
        }
    }
}


struct Init
{
    int a;
    int b;
    Init()
    {
        a = b = 1;
    }
};


#endif //PCH_H
