/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int index = 0;
        vector<int> nums(nums1.size() + nums2.size(), 0);
        for (int num: nums1)
            nums[index++] = num;
        for (int num: nums2)
            nums[index++] = num;

        sort(nums.begin(), nums.end(), [](int x, int y){ return x > y;});

        double out;
        if (nums.size() % 2 == 0)
        {
            out = nums[nums.size() / 2 - 1] + nums[nums.size() / 2];
            out /= 2;
        }else
        {
            out = nums[nums.size() / 2];
        }
        

        return out;
    }
};
// @lc code=end

