#include "pch.h"

void ShowTimeFormat()
{
	std::cout << "\t\t**Hello World!**\t\t\n";

	time_t tmNowTime = time(0);
	char byTimeStr[50] = { 0 };
	ctime_s(byTimeStr, 50, &tmNowTime);
	std::cout << "\t\t**���ڵ�ʱ���ǣ�" << byTimeStr << std::endl;

	//������ʱ�� ��ʱ��  //fix����ָ��ʱ���
	cout << "\t\t**��1970�굽���ڵ�ʱ�䣺" << tmNowTime << endl;
}
