#include "pch.h"
#include "StructDefine.h"


void StructDefine()
{
	Mytest cMyTest;
	cMyTest.show();

	//Single
	cout << "\tSingle Start" << endl;
	{
		AStruct tAs;
		cout << "\ttAs:"<< tAs.dwAstruct << endl;
		Aclass cAc;
	}
	cout << "\tSingle End" << endl;

	//contain
	cout << "\tContain Start" << endl;
	{
		SConStruct sConS;
		SConClass  sConC;
	}
	{
		CconStruct cConS;
		CConClass  cConC;
	}
	cout << "\tContain End" << endl;

	//inherit
	cout << "\tInherit Start" << endl;
	{
		SInherStruct sInherS;
		SInherClass  sinherC;
	}
	{
		CInherStruct cInherS;
		CInherClass  cInherC;
	}
	cout << "\tInherit End" << endl;

	return;
}