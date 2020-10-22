// 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
//     你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
//"vtkgn"
//"vttkgnn"
// "alex"
// "aaleex"
#include "origin.hpp"
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        if (name.length() > typed.length())
            return false;
        if (name == typed)
            return true;
        if (name[0] != typed[0])
            return false;
        int i = 0,
            j = 0;
        while (i < name.length())
        {
            if (name[i] == typed[j])
            {
                i++;
                j++;
            }
            else if (name[i] != typed[j] && typed[j] == typed[j - 1])
            {
                j++;
            }
            else
            {
                return false;
            }
        }
        while (j < typed.length()) //末尾校验
        {
            if (typed[j] != name[i - 1])
                return false;
            j++;
        }
        return true;
    }
};

void UserTest::usertest()
{
    string name = "alex";
    string typed = "aaleex";
    Solution s;
    bool bret = s.isLongPressedName(name, typed);
    cout << bret << endl;
}