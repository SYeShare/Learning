// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <vector>


using namespace std;


inline double square(double x) { return x*x; }
const double* f1(const double ar[], int n);
const double * f2(const double[], int);
const double *f3(const double*, int);

struct A
{
	int i;
	int j;
};

struct B
{
	int i;
	bool b;
	int j;
};
// struct A
// {
// 	int i;
// 	int *p;
// public:
// 	A() :p(0) { cout << "A:A()" << endl; }
// };

struct testtmp
{
    int i;
    int j;

    testtmp() {
        i = 1;
        j = 2;
    }
};



typedef int Type;

typedef struct TreeBasic
{

}tree;

#define KDV_MAX_IPADDR_STR_LEN	48
#define KDV_NET_ANYADDR		"::"
typedef struct {
    char addr[KDV_MAX_IPADDR_STR_LEN];
} kdv_netaddr;

#define KDV_NET_ANYADDR		"::"
#define KDV_NET_ANYADDR_LEN	2
static const kdv_netaddr kdv_net_anyaddr = { KDV_NET_ANYADDR };

#define str2netaddr(kdvstr, kdvstr_len, paddr) { 	\
	if (!(kdvstr) || !(kdvstr_len)) {	\
		*paddr = kdv_net_anyaddr;		\
	} else {								\
		int netaddr_len__ = (kdvstr_len) < (KDV_MAX_IPADDR_STR_LEN - 1)  ? kdvstr_len : (KDV_MAX_IPADDR_STR_LEN - 1);	\
		memcpy(&((paddr)->addr[0]), kdvstr, netaddr_len__);	\
		(paddr)->addr[netaddr_len__] = '\0';		\
	}	\
}

#define netaddr2str(paddr)	((char*)&((paddr)->addr[0]))

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
