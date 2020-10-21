//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//输入: "abcabcbb"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

#include "origin.hpp"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() < 1)
            return s.length();

        int maxsublen = 0;
        unordered_set<int> set;
        int left = 0;
        for (int i = 0; i < s.length(); i++)
        {
            while (set.find(s[i]) != set.end())
            {
                set.erase(s[left]);
                left++;
            }
            set.insert(s[i]);
            maxsublen = max(maxsublen, i - left + 1);
        }
        return maxsublen;
    }
};