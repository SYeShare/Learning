#include "pch.h"

void ShowTimeFormat()
{
	std::cout << "\t\t**Hello World!**\t\t\n";

	time_t tmNowTime = time(0);
	char byTimeStr[50] = { 0 };
	ctime_s(byTimeStr, 50, &tmNowTime);
	std::cout << "\t\t**现在的时间是：" << byTimeStr << std::endl;

	//计算总时间 耗时：  //fix计算指定时间差
	cout << "\t\t**从1970年到现在的时间：" << tmNowTime << endl;
}
