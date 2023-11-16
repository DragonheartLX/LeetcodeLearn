/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
/*        
        unordered_map<char, int> hashMap;

        if(s.empty())
            return 0;

        for (int i = 0; i < s.size(); i++)
        {
            auto it = hashMap.find(s[i]);
            if (it == hashMap.end())
                hashMap.emplace(s[i], i);
            else
                it->second = i;
        }
        
        int count = 1;

        for(auto it: hashMap){
            if (it.second < count)
                count = it.second;
        }

        return count;
*/
        if (s.empty())
            return 0;
        
        int size = s.size();
        int index = 0;
        int count = 1;

        unordered_map<char,int> hashMap;
        for (int i = 0; i < size; i++)
        {
            hashMap.clear();
            hashMap.emplace(s[i], i);
            for (index = i + 1; index < size; index++)
            {
                if (hashMap.find(s[index]) == hashMap.end())
                {
                    hashMap.emplace(s[index], index);
                }else
                    break;
            }
            count = count < (index - i) ? (index - i) : count;
        }
        
        return count;

    }
};
// @lc code=end

