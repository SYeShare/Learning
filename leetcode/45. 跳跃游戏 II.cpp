// 给定一个非负整数数组，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
#include "origin.hpp"

class Solution
{
public:
    //2020-10-22 23:37:11
    int jump_sec(vector<int> &nums)
    {
        //check
        if (nums.size() < 2)
            return 0;

        int start = 0;
        int end = 1;
        int maxpos = 0;
        int count = 0;

        while (end < nums.size())
        {
            while (start < end)
            {
                maxpos = max(maxpos, nums[start] + start);
                start++;
            }
            start = end;
            end = maxpos + 1;
            count++;
        }
        return count;
    }

    int jump(vector<int> &nums)
    {
        int cout = 0;
        int start = 0;
        int end = 1;
        int size = nums.size();

        while (end < size)
        {
            int maxpos = 1;
            while (start < end)
            {
                maxpos = max(maxpos, start + nums[start]);
                start++;
            }
            start = end;
            end = maxpos + 1;
            cout++;
        }
        return cout;
    }
};