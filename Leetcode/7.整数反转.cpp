/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // 反转操作简单,难点在于溢出判断
        
        int out = 0;

        while (x)
        {
            int tmp = x % 10;
            x /= 10;

            /*
                INT_MIN <= out * 10 + tmp <= INT_MAX
                INT_MIN / 10 <= out + tmp / 10 <= INT_MAX / 10
                (INT_MIN - tmp) / 10 <= out <= (INT_MAX - tmp) / 10
                INT_MIN / 10 <= out <= INT_MAX / 10 - tmp / 10
            */

            if (INT_MIN / 10 <= out && out <= INT_MAX / 10 - tmp / 10)
                out = out * 10 + tmp;
            else
                return 0;
        }
        
        return out;
    }
};
// @lc code=end

