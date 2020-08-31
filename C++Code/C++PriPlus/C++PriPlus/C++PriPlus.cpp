// C++PriPlus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

testtmp tst[10];

int main()
{
    //最长无重复子串


    //初始化
    char tmp = 25;
    cout << tmp << endl;

    for (int i = 0;i<10;i++)
    {
        cout << tst[i].i << "----";
        cout << tst[i].j << endl;
    }
    cout << "size:" << sizeof(tst) << endl;
    memset(tst, 0, sizeof(tst));
    for (int i = 0; i < 10; i++)
    {
        cout << tst[i].i << "----" << tst[i].j << endl;
    }



    /*
    kdv_netaddr netaddr;
    str2netaddr(KDV_NET_ANYADDR, 0, &netaddr);

    int bRet = strncmp(netaddr2str(&netaddr), ":", strlen(KDV_NET_ANYADDR));
    cout << bRet << endl;
    */
    /*
	//  [8/21/2019 suzhibin]
	cout << "hello https://tool.lu/" << endl;

	string str1 = "I";
	string str2 = "love";
	string str3 = str1 + "eat" + "apple";
	cout << str3 << endl;
    */

// 
// 	A a;
// 	a.i = 1;
// 	a.j = 2;
// 
// 	B *b = (B*)a;
// 	cout << "i" << b->i << "j" << b->j << endl;



	//  [12/3/2018 sushare]
#if 1


#endif

	//2018年11月13日
#if 1


#endif




	//2018年11月10日
#if 0
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5); 

#endif


#if 0 //2018年11月8日
	

	double av[3] = { 1112.3, 1542.6, 2227.9 };

	const double *(*p1)(const double*, int) = f1;
	auto p2 = f2;
	cout << "address value\n";
	cout << (*p1)(av, 3) << ":" << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << ":" << *p2(av, 3) << endl;

	const double *(*pa[3])(const double *, int) = { f1,f2, f3 };
	auto pb = pa;
	cout << "\nUsing an array of pointer to functions:\n";
	cout << "Address Value\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pa[i](av, 3) << ":" << *pa[i](av, 3) << endl;
	}

	cout << "\nUsing an pointer to a pointer to a function:\n";
	cout << "address value\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pb[i](av, 3) << ":" << *pb[i](av, 3) << endl;
	}

	cout << "\nUsing pointer to an array of pointers:\n";
	cout << "Address Valus\n";
	auto pc = &pa;
	cout << (*pc)[0](av, 3) << ":" << *(*pc)[0](av, 3) << endl;

	const double *(*(*pd)[3])(const double *, int) = &pa;

	const double * pdb = (*pd)[1](av, 3);
	cout << pdb << ":" << *pdb << endl;

	cout << (*(*pd)[2])(av, 3) << ":" << *(*(*pd)[2])(av, 3) << endl;

	//typedef to down mistake/nums
	typedef const double *(*p_fun)(const double *, int);
	p_fun p1 = f1;

	p_fun pa[3] = { f1,f2,f3 };
	p_fun(*pd)[3] = &pa;


#endif
#if 0
	//2018年11月7日
	//函数指针  & 指针函数

#endif

	printf("Here is end.\n");
	system("pause");
    return 0;
}

// map<int, string>hT;
// char*plot(map* hT);
void ignor(int);
void a1(int arr[], int len, int vlue);
void a2(int *p1, int *p2, int value);
int fn(int n)
{
	return n * fn(n - 1);
}
const double *f1(const double *ar, int n)
{
	return ar;
}

const double *f2(const double ar[], int n)
{
	return ar + 1;
}

const double *f3(const double ar[], int n)
{
	return ar + 2;
}
