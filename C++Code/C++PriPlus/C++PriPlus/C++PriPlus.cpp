// C++PriPlus.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
	//2018��11��10��
#if 1
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5); 

	


#endif


#if 0 //2018��11��8��
	

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
	//2018��11��7��
	//����ָ��  & ָ�뺯��

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
