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
#if 0  //�����ͼ̳�
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
		//SConStruct sConS;
		//SInherClass sInherC;
		//CConClass cConC;
		CInherStruct cInherS;
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
		//��ʼ���б�-֮���������ʼ�������˽�г�Ա
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
				Test(110);            //  ���캯��ֻ���ڳ�ʼ���б��б���ʾ���ã�
									  //�����ڹ��캯���ڲ�����ʾ����.  ����Test�������������ֻ��{}��
			};
		};

		Mytest myTest;
		myTest.show();
	}

#endif

	return;
}