/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        update(s);
        update(t);
        return s==t;
    }
    void update(string &s){
        int slow=0;
        for(int fast=0;fast<s.size();fast++){
            if(s[fast]=='#'){
                slow--;
            }else{
                s[slow++]=s[fast];
            }
            if(slow<0)slow=0;
        }
        s.resize(slow);
    }
};
// @lc code=end

