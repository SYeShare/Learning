#pragma once
#include "pch.h"

//base基础DATA
struct AStruct
{
	int dwAstruct;
	int sa;

	AStruct():sa(1)
	{
		cout << sa << endl;
	}
	~AStruct(){ cout << "~AStruct()" << endl; }

};

class  Aclass
{
private:
	int dwAclass;
public:
	Aclass():dwAclass(44)
	{
		cout<< dwAclass <<endl;
	}
	~Aclass(){ cout << "~Aclass()" << endl; }
};

//Contain
struct SConStruct
{
	AStruct tA;
	int  b;
	/*Aclass cA;*/
	SConStruct():b(2)
	{
		cout<<b<<endl;
	};
	~SConStruct(){ cout << "~SConStruct()" << endl; }
};


struct SConClass
{
	Aclass cA;
	SConClass(){ cout << "SConClass()" << endl; }
	~SConClass(){ cout << "~SConClass()" << endl; }
};

class CConClass
{
public:
	CConClass(){ cout << "CConClass()" << endl; }
	~CConClass(){ cout << "~CConClass()" << endl; }

private:
	Aclass cA;
};


class CconStruct
{
public:
	CconStruct(){ cout << "CconStruct()" << endl; }
	~CconStruct(){ cout << "~CconStruct()" << endl; }

private:
	AStruct sS;
};

//Inherit
struct SInherStruct:AStruct
{
	SInherStruct(){ cout << "SInherStruct()" << endl; }
	~SInherStruct(){ cout << "~SInherStruct" << endl; }
};


struct SInherClass : Aclass
{
	SInherClass(){ cout << "SInherClass()" << endl; }
	~SInherClass(){ cout << "~SInherClass()" << endl; }
};


class CInherStruct : AStruct
{
public:
	CInherStruct(){ cout << "CInherStruct()" << endl; }
	~CInherStruct(){ cout << "~CInherStruct()" << endl; }
};


class CInherClass : Aclass
{
	int cCin;
public:
	CInherClass():cCin(55),Aclass()
	{
		cout << "CInherClass()" << endl;
	}
	~CInherClass() { cout << "~CInherClass()" << endl; }

};

//初始化列表一：仅含参构造


//初始化列表二：const & 引用 


