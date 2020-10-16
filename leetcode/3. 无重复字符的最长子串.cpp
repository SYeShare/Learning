#include "origin.hpp"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;

        unordered_set<char> lookup;

        int maxstr = 0;
        int left = 0;

        for (int i = 0; i < s.size(); i++)
        {
            while (lookup.find(s[i]) != lookup.end())
            {
                lookup.erase(s[left]);
                left++;
            }
            maxstr = max(maxstr, i - left + 1);
            lookup.insert(s[i]);
        }
        return maxstr;
    }
};