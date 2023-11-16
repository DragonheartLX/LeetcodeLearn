/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int center = 0, count = 0;
        int left = 0, right = 0;

        string out = s;

        // 字符串大小小于 2 的处理
        if (s.size() <= 1)
            return out;

        if (s.size() <= 2)
            return (s[0] == s[1]) ? out : out.substr(0, 1);
        

        // 奇数回文字
        for (center = 1; center < s.size() - 1; center++)
        {
            for (left = right = center; left >=0 && right < s.size(); left--, right++)
            {
                if (s[left] != s[right])
                    break;
            }
            
            if ((right - left - 1) > count)
            {
                count = right - left - 1;
                out = s.substr(left + 1, right - left - 1);
            }

        }

        // 偶数回文字
        for (center = 0; center < s.size() - 1; center++)
        {
            for (left = center, right = center + 1; left >=0 && right < s.size(); left--, right++)
            {
                if (s[left] != s[right])
                    break;
            }
            
            if ((right - left - 1) > count)
            {
                count = right - left - 1;
                out = s.substr(left + 1, right - left - 1);
            }

        }

        return out;
    }
};
// @lc code=end

