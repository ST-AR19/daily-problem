/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for(int i=0; i<s.size(); i++){
            if(result.empty() || result.back() != s[i]) result.push_back(s[i]);
            else result.pop_back();
        }
        return result;
    }
};
// @lc code=end

