/*给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置*/

#include "origin.hpp"
class Solution
{
public:
    bool canjump_sec(vector<int> &nums)
    {
    }

    bool canJump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return true;

        int start = 0;
        int end = 0;
        int maxpos = 0;

        while (end < nums.size())
        {
            for (int i = start; i <= end; i++)
            {
                maxpos = max(maxpos, nums[i] + i);
            }
            start = end;
            end = maxpos;

            if (end == nums.size() - 1)
            {
                return true;
            }
            if (start == end)
            {
                return false;
            }
        }
        return true;
    }
};