// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// C++PriPlus.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

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
// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������
