// stdafx.cpp : 只包括标准包含文件的源文件
// C++PriPlus.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

//
class TreeNode{
    int val;
    TreeNode *cleft;
};



//20200819计算素数
int CountSuShu(int n)
{
    vector<bool> Vec(n, true);

    for (int i = 2; i*i < n ; i++)
    {
        if (Vec[i])
        {
            for (int j = 2*i ; j < n ; j+=i)
            {
                Vec[j] = false;
            }
        }
    }

    int sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if (Vec[i])
        {
            sum++;
        }
    }
    return sum;
}




//20200713斐波那契数列  ；
//带备忘录的递归解法
//1
int helper(vector<int> &memo, int n)
{
    if (n == 1 || n == 2)     return 1;
    if (memo[n] != 0)    return memo[n];

    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}
int fib1(int n)
{
    if (n<1)
    {
        return 0;
    }
    vector<int> memo(n+1, 0);
    return helper(memo, n);
}

//2  状态转移方程；
int fib2(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = dp[2] = 1;
    for (int i = 3;i<n;i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
//3  -- 状态压缩
int fib3(int n)
{
    if (n == 2 || n == 1)  return 1;
    
    int prev = 1, curr = 1;
    for (int i =3;i<=n;i++)
    {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
}





#if 0
template <typename AnyType>
void Swap(AnyType &a, AnyType &b)
{
	AnyType temp;
	temp = a;
	a = b;
	b = temp;
}

template <class T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = a;
}
#endif
// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用
