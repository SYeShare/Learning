// stdafx.cpp : 只包括标准包含文件的源文件
// C++PriPlus.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

struct A 
{
	int i;
	int *p;
public:
	A() :p(0) { cout << "A:A()" << endl; }
};


template <typename AnyType>
void Swap(AnyType &a, AnyType &b)
{
	AnyType temp;
	temp = a;
	a = b;
	b = temp;
}

template <class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = a;
}
// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用
