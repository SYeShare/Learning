// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
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


// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
