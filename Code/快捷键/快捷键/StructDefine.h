#pragma once
#include "pch.h"

//base基础DATA
struct AStruct
{
	AStruct();
	~AStruct();
	int dwAstruct;
};
AStruct::AStruct()
{
	cout << "AStruct()" << endl;
}
AStruct::~AStruct()
{
	cout << "~AStruct()" << endl;
}

class  Aclass
{
private:
	int dwAclass;
public:
	Aclass();
	~Aclass();
};

Aclass::Aclass()
{
	cout << "Aclass()" << endl;
}

Aclass::~Aclass()
{
	cout << "~Aclass()" << endl;
}


//Contain
struct SConStruct
{
	AStruct tA;
	/*Aclass cA;*/
	SConStruct();
	~SConStruct();
};
SConStruct::SConStruct()
{
	cout << "SConStruct()" << endl;
}
SConStruct::~SConStruct()
{
	cout << "~SConStruct()" << endl;
}

struct SConClass
{
	Aclass cA;
	SConClass();
	~SConClass();
};
SConClass::SConClass()
{
	cout << "SConClass()" << endl;
}
SConClass::~SConClass()
{
	cout << "~SConClass()" << endl;
}

class CConClass
{
public:
	CConClass();
	~CConClass();

private:
	Aclass cA;
};

CConClass::CConClass()
{
	cout << "CConClass()" << endl;
}

CConClass::~CConClass()
{
	cout << "~CConClass()" << endl;
}

class CconStruct
{
public:
	CconStruct();
	~CconStruct();

private:

};

CconStruct::CconStruct()
{
	cout << "CconStruct()" << endl;
}

CconStruct::~CconStruct()
{
	cout << "~CconStruct()" << endl;
}



//Inherit
struct SInherStruct:AStruct
{
	SInherStruct();
	~SInherStruct();
};
SInherStruct::SInherStruct()
{
	cout << "SInherStruct()" << endl;
}
SInherStruct::~SInherStruct()
{
	cout << "~SInherStruct" << endl;
}

struct SInherClass : Aclass
{
	SInherClass();
	~SInherClass();
};
SInherClass::SInherClass()
{
	cout << "SInherClass()" << endl;
}
SInherClass::~SInherClass()
{
	cout << "~SInherClass()" << endl;
}

class CInherStruct : AStruct
{
	CInherStruct();
	~CInherStruct();
};
CInherStruct::CInherStruct()
{
	cout << "CInherStruct()" << endl;
}
CInherStruct::~CInherStruct()
{
	cout << "~CInherStruct()" << endl;
}

class CInherClass : Aclass
{
public:
//自动补全的构造函数， 属于继承fix 测试确认
	CInherClass : Aclass();
	~CInherClass : Aclass();

	CInherClass();
	~CInherClass();

private:

};

CInherClass::CInherClass()
{
	cout << "CInherClass()" << endl;
}
CInherClass::~CInherClass()
{
	cout << "~CInherClass()" << endl;
}

CInherClass : Aclass::CInherClass : Aclass()
{
	cout << "CInherClass : Aclass()" << endl;
}

CInherClass : Aclass::~CInherClass : Aclass()
{
	cout << "~CInherClass : Aclass()" << endl;
}