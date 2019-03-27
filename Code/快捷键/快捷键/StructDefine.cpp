#include "pch.h"
#include "StructDefine.h"


void StructDefine()
{
// 	Mytest cMyTest;
// 	cMyTest.show();

	//Single
// 	cout << "\tSingle Start" << endl;
// 	{
// 		AStruct tAs;
// 		Aclass cAc;
// 	}
// 	cout << "\tSingle End" << endl;
#if 0  //包含和继承
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

#endif


	{

	}





#if 0
	{
		class CConst {
		public:
			const int m_dwConst;
			CConst():m_dwConst(10) {}
		};


	}



	{
		//初始化列表-之三：子类初始化父类的私有成员
		class Test {
		public:
			Test() { cout << "Test void" << endl; }
			Test(int x) { cout << "Test Int" << endl; int_x = x; }
			void show() { cout << "int_x = " << int_x << endl; }
		private:
			int int_x;
		};

		class Mytest : public Test {
		public:
			Mytest() /*: Test(110)*/ {
				Test(110);            //  构造函数只能在初始化列表中被显示调用，
									  //不能在构造函数内部被显示调用.  否则Test对象的生命周期只在{}内
			};
		};

		Mytest myTest;
		myTest.show();
	}

#endif

	return;
}