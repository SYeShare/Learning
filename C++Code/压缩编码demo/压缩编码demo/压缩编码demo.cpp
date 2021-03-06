// 压缩编码demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

using namespace std;
int main()
{
    std::cout << "Hello World!\n";

	//  [1/9/2020 suzhibin]
	{//vector
		std::vector<TMtInfo> TMtBuf;
		TMtInfo tMtInfo;
		//string aliastmp[5] = { "000","111","222","333","444" };
		{
			TMtBuf.push_back(tMtInfo);
			memcpy(TMtBuf[0].alias, "000", 4);
			TMtBuf[0].setnum(0);
			TMtBuf[0].print();
			TMtBuf.push_back(tMtInfo);
			memcpy(TMtBuf[1].alias, "111", 4);
			TMtBuf[1].setnum(1);
			TMtBuf[1].print();
			TMtBuf.push_back(tMtInfo);
			memcpy(TMtBuf[2].alias, "222", 4);
			TMtBuf[2].setnum(2);
			TMtBuf[2].print();
			TMtBuf.push_back(tMtInfo);
			memcpy(TMtBuf[3].alias, "333", 4);
			TMtBuf[3].setnum(3);
			TMtBuf[3].print();
		}
		std::vector<TMtInfo>::iterator iter = TMtBuf.begin();
		iter++;
		TMtBuf.erase(iter);
		for (int i = 0; i < TMtBuf.size(); i++)
		{
			TMtBuf[i].print();
		}
	}

#if 0
	{
		union unTest
		{
			int i;
			int *p;
		}; 
		unTest unTd;
		int temp = 2;

		unTd.p = &temp;

		cout << *unTd.p << endl;
	}



	{//  [12/4/2019 suzhibin]
		std::vector<int>m_Vec;

		m_Vec.push_back(1);
		m_Vec.push_back(2);
		int i = 0;
		std::vector<int>::iterator iter = m_Vec.begin();
		while (iter != m_Vec.end())
		{
			cout << "i = " << i  << endl;
			i++;
			iter = m_Vec.erase(iter);
		}
		cout << "size:" << m_Vec.size() << endl;
		while (1);

	}
#endif
#if 0
	{//  [10/21/2019 suzhibin] new与指针
		TMsgBuf *pTBuf = NULL;
		if (TRUE)
		{
			char *pLongBuf = new char[200];
			TMsgBuf tMsg;
			for (int i = 0; i < 10; i++)
			{
				tMsg.data = i;
				tMsg.month = i;

				memcpy(pLongBuf, (char*)&tMsg, sizeof(tMsg));
				pLongBuf += sizeof(tMsg);
			}
			pLongBuf -= 10 * sizeof(tMsg); //位移

			pTBuf = (TMsgBuf*)pLongBuf;
			//memcpy(pTBuf, (TMsgBuf*)pLongBuf, 200);
			if (pLongBuf != NULL)
			{
// 				cout << "LongBuf:" << pLongBuf << endl;
// 				delete[]pLongBuf;
// 				pLongBuf = NULL;
			}
		}

		//tmsg=(TMsgBuf*)pLongBuf;
		for (int j=0;j<10;j++)
		{
			cout << pTBuf[j].data << endl;
		}

		//memset(pLongBuf, 0, 200);
// 		TMsgBuf*tmsg2 = nullptr;
// 		tmsg2 = (TMsgBuf*)pLongBuf;
// 		for (int j = 0; j < 10; j++)
// 		{
// 			cout << tmsg2[j].data << endl;
// 		}

// 		if (TRUE)
// 		{
// 			char * pNewBuf = new char[200];
// 			char bylen = 0;
// 			char j = 1;
// 			for (char i = 0;i<10 ; i++)
// 			{
// 				memcpy(pNewBuf + bylen, (char*)&j, sizeof(i));
// 				cout << pNewBuf[i] << "\t & len :"<< bylen <<endl;
// 				bylen += sizeof(j);
// 				j++;
// 			}
// 			ptbuf = pNewBuf;
// 			if (pNewBuf!=NULL)
// 			{
// 				delete[]pNewBuf;
// 				pNewBuf = NULL;
// 			}
// 		}

// 		for (char i = 0;i<10 ;i++)
// 		{
// 			cout << "ptbuf:"<<ptbuf[i] << endl;
// 		}


	}






	{// 传参 [3/11/2019 suzhibin]
		int dwArraySize = 0;
		char bTemp = 1;
		if (bTemp)
		{
			dwArraySize = 10;
		}
		else
		{
			dwArraySize = 2;
		}
		CopySomeThing(dwArraySize);
	}

	{// 数组传参 [3/5/2019 suzhibin]
		MyStruct abyContent[5] = { {1,1},{1,1},{1,1},{1,1},{1,1} };

		cout << "main: sizeof arry:" << sizeof(abyContent) << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "main(): array:" << abyContent[i].m_byNum << endl;
		}
		TransArrayToCopy(abyContent);
		for (int i = 0; i < 5; i++)
		{
			cout << "main(): array:" << abyContent[i].m_byNum << endl;
		}
	}

#endif
	while (1)
	{
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
