/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] N 字形变换
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {

        // numRows = 1 时数组会越界, 原因未探究也无必要,直接返回即可
        if (numRows <= 1)
            return s;
        
        bool flag = false;
        vector<string> str(numRows);
        int row = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (row == numRows - 1)
                flag = true;

            if (row == 0)
                flag = false;

            if (flag)
            {
                str[row] += s[i];
                row--;
            }else
            {
                str[row] += s[i];
                row++;
            }
            
        }
        
        string out;

        for (string it : str)
            out += it;

        return out;
    }
};
// @lc code=end

