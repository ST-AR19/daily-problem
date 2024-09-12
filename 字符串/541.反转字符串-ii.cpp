/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int slow=0,fast=0;
        while(fast != s.size()-1){
            fast++;
            if(fast % (k*2) == 0){
                reverse(s.begin()+slow,s.begin()+slow+k);
                slow = fast;
            }
        }
        if(s.size()-1-slow < k) reverse(s.begin()+slow,s.end());
        else reverse(s.begin()+slow,s.begin()+slow+k);
        return s;
    }
};
// @lc code=end

