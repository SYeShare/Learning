#pragma once
#include "pch.h"

//base»ù´¡Àà
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

