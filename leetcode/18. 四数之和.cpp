// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
//使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
//     注意：
//         答案中不可以包含重复的四元组。
//     示例：
//         给定数组 nums = [ 1, 0, -1, 0, -2, 2 ] ，和 target = 0。
//     满足要求的四元组集合为：
//         [
//             [ -1, 0, 0, 1 ],
//             [ -2, -1, 1, 2 ],
//             [ -2, 0, 0, 2 ]]
#include "origin.hpp"
class Solution
{
public:
    //2020-10-23 00:05:39
    vector<vector<int>> fourSum_sec(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        int a, b, c, d, size = nums.size();

        //error：缺少排序

        for (a = 0; a < size - 4; a++) //error:应该是 <=
        {
            if (a > 1 && nums[a - 1] > nums[a])
                continue;

            for (b = a + 1; b < size - 3; b++)
            {
                if (b > a + 1 && nums[b - 1] == nums[b])
                {
                    continue;
                }

                c = b + 1;
                d = size - 1;

                while (c < d)
                {
                    if (nums[a] + nums[b] + nums[c] + nums[d] > target)
                    {
                        d--;
                    }
                    else if (nums[a] + nums[b] + nums[c] + nums[d] < target)
                    {
                        c++;
                    }
                    else
                    {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c + 1] == nums[c])
                            c++;
                        while (c < d && nums[d - 1] == nums[d])
                            d--;
                    }
                    c++;
                    d--;
                }
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        int a, b, c, d;

        for (a = 0; a < nums.size() - 4; a++)
        {
            if (a > 1 && nums[a - 1] == nums[a])
                continue;
            for (b = a + 1; b < nums.size() - 3; b++)
            {
                if (b > a + 2 && nums[b - 1] == nums[b])
                    continue;

                c = b + 1;
                d = nums.size() - 1;
                if (nums[a] + nums[b] + nums[c] + nums[d] > target)
                {
                    d--;
                }
                else if (nums[a] + nums[b] + nums[c] + nums[d] < target)
                {
                    c++;
                }
                else
                {
                    while (c < d)
                    {
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c + 1 < d && nums[c + 1] == nums[c])
                        {
                            c++;
                        }
                        while (d - 1 > c && nums[d - 1] == nums[d])
                        {
                            d--;
                        }
                        c++;
                        d--;
                    }
                }
            }
        }
        return res;
    }
};