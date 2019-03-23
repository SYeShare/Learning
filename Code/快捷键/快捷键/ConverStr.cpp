#include "pch.h"

void ConverStrBySscanf()
{
	// ≤‚ ‘sscanf 
	char achStrTemp[100] = " hello , World,  1234dps   , 100   ";

	char achInterTmp[20] = "wor  ld  ";

	int dwInter = 0;
	char achtemp1[20] = { 0 };
	char achtemp2[20] = { 0 };
	char achtemp3[20] = { 0 };
	char achtemp4[20] = { 0 };
	char achtemp5[20] = { 0 };

	sscanf(achStrTemp, "%*[^0-9a-zA-Z]%[^(, )]%*[^0-9a-zA-Z]%[^(, )]%*[^0-9a-zA-Z]%[^(, )]%*[^0-9a-zA-Z]%[^(, )]", achtemp1, achtemp2, achtemp3, achtemp4);

	sscanf(achInterTmp, "%[ a-z]",achtemp5);

	cout << "\tachTemp1:" << achtemp1 << "," << endl;
	cout << "\tachTemp2:" << achtemp2 << "," << endl;
	cout << "\tachTemp3:" << achtemp3 << "," << endl;
	cout << "\tachTemp4:" << achtemp4 << "," << endl;
	cout << "\tachTemp5:" << achtemp5 << "," << endl;

	// 	int dwRet = sscanf(achInterTmp, "CAP%d", &dwInter);
	// 	if (dwRet == EOF || dwRet == 0)
	// 	{
	// 		cout << "\t EOF dwRet:" << dwRet << endl;
	// 	}
	// 	else
	// 	{
	// 		cout << "\t Value dwRet:" << dwRet << endl;
	// 	}
	// 
	// 	cout << "\t dwInter:" << dwInter << endl;
}