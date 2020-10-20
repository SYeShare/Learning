// 给定仅有小写字母组成的字符串数组
// A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
// 例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
// 你可以按任意顺序返回答案。

// 示例 1：
// 输入：["bella","label","roller"]
// 输出：["e","l","l"]
// 示例 2：
// 输入：["cool","lock","cook"]
// 输出：["c","o"]

#include "origin.hpp"

class Solution
{
public:
    vector<string> commonChars(vector<string> &A)
    {
        vector<string> res;
        if (A.size() == 0)
        {
            return res;
        }
        int hash[26] = {0};

        for (int i = 0; i < A[0].size(); i++)
        {
            hash[A[0][i] - 'a']++;
        }

        int hashother[26] = {0};
        for (int j = 1; j < A.size(); j++)
        {
            for (int z = 0; z < A[j].size(); z++)
            {
                hashother[A[j][z] - 'a']++;
            }
            for (int k = 0; k < 26; k++)
            {
                hash[k] = min(hash[k], hashother[k]);
            }
            memset(hashother, 0, 26);
        }

        for (int i = 0; i < 26; i++)
        {
            while (hash[i] != 0)
            {
                string s(1, i + 'a');
                res.emplace_back(s);
                hash[i]--;
            }
        }
        return res;
    }
};