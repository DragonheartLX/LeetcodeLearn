/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        // 删除前导空格
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;

            s = s.substr(i, s.size() - i);
            break;
        }

        // 判断正负
        // '-' 
        // '*'
        // '+'
        bool sign = false;
        switch (s[0])
        {
            case '-':
                sign = true;
            case '+':
                s = s.substr(1, s.size() - 1);
            break;
        
            default:
            break;
        }

        // 提取数字
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] <= '9' && s[i] >= '0')
                continue;

            s = s.substr(0, i);
            break;
        }

        // 转换数字
        if (s.empty())
            return 0;      

        int out = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int ch = s[i] - 48;
            if (out > INT_MAX / 10 || (out == INT_MAX / 10 && ch > 7))
                return sign ? INT_MIN : INT_MAX;

            out = out * 10 + ch;
        }
        
        return sign ? -out : out;
    }
};
// @lc code=end

