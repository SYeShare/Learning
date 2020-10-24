/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，
同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
*/
#include "origin.hpp"
class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> res;
        unordered_map<char, int> ordermap;
        for (int i = 0; i < S.length(); i++)
        {
            ordermap[S[i]] = i;
        }
        int start = 0, end = 0;

        for (int j = 0; j < S.length(); j++)
        {
            end = max(end, ordermap[S[j]] - end);
            if (j == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return res;
    }
};