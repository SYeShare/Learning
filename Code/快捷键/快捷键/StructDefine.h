#pragma once
#include "pch.h"

//base基础DATA
class  Aclass
{
private:
	int dwAclass;
public:
	Aclass() :dwAclass(44)
	{
		cout << "Aclass().dAwclass" << dwAclass << endl;
	}
	~Aclass() { cout << "~Aclass()" << endl; }
	int GetAC() { return dwAclass; }
};

struct AStruct:Aclass
{
	int sa;

	AStruct():sa(1)
	{
		cout <<"AStruct():sa"<< sa << endl;
	}
	~AStruct(){ cout << "~AStruct()" << endl; }

};



//Contain
struct SConStruct
{
	int A;
	AStruct tB;
	int  C;
	Aclass cD;
	int E;
	SConStruct():A(2),C(3),E(4)
	{
		cout<<"SConStruct().A:"<< A <<endl;
		cout<<"SConStruct().tB:"<< tB.sa <<endl;
		cout<<"SConStruct().C:"<< C <<endl;
		cout<<"SConStruct().cD:"<< cD.GetAC() <<endl;
		cout<<"SConStruct().E:"<< E <<endl;
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
private:
	int A;
	AStruct tB;
	int  C;
	Aclass cD;
	int E;
public:
	CConClass() : C(3), E(4),A(2)
	{
		cout << "CConClass().A:" << A << endl;
		cout << "CConClass().tB:" << tB.sa << endl;
		cout << "CConClass().C:" << C << endl;
		cout << "CConClass().cD:" << cD.GetAC() << endl;
		cout << "CConClass().E:" << E << endl;
	};


	//CConClass(){ cout << "CConClass()" << endl; }
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
	int A;
	AStruct tB;
	int  C;
	SInherClass() :C(2), A(3)
	{
		cout << "SInherClass().A:" << A << endl;
		cout << "SInherClass().tB:" << tB.sa << endl;
		cout << "SInherClass().C:" << C << endl;
		cout << "SInherClass().AC:" << GetAC() << endl;
	};



	~SInherClass(){ cout << "~SInherClass()" << endl; }
};


class CInherStruct : AStruct
{
private:
	int a;

private:
	int A;
	AStruct tB;
	int  C;
	Aclass cD;
	int E;
public:
	CInherStruct() : C(3), E(4), A(2)
	{
		cout << "CConClass().A:" << A << endl;
		cout << "CConClass().tB:" << tB.sa << endl;
		cout << "CConClass().C:" << C << endl;
		cout << "CConClass().cD:" << cD.GetAC() << endl;
		cout << "CConClass().E:" << E << endl;
	};

public:
	//CInherStruct(){ cout << "CInherStruct()" << endl; }
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


