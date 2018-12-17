// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
using namespace std;


inline double square(double x) { return x*x; }
const double* f1(const double ar[], int n);
const double * f2(const double[], int);
const double *f3(const double*, int);



// TODO:  在此处引用程序需要的其他头文件
