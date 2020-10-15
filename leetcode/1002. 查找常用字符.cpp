// ��������Сд��ĸ��ɵ��ַ������� A�������б��е�ÿ���ַ����ж���ʾ��ȫ���ַ�
//�������ظ��ַ�����ɵ��б����磬���һ���ַ���ÿ���ַ����г��� 3 �Σ�
//������ 4 �Σ�����Ҫ�����մ��а������ַ� 3 �Ρ�
//     ����԰�����˳�򷵻ش𰸡�
// ʾ�� 1��
// ���룺["bella","label","roller"]
// �����["e","l","l"]
// ʾ�� 2��
// ���룺["cool","lock","cook"]
// �����["c","o"]

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