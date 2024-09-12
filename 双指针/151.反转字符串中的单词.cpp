/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
    void reverse(string& s, int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }
    void removeExtraSpace(string& s){
        int slow = 0;
        for(int fast = 0;fast<s.size();++fast){
            if(s[fast]!=' '){
                if(slow!=0)s[slow++]=' ';
                while(s[fast]!=' ' && fast<s.size()){
                    s[slow++]=s[fast++];
                }
            }
        }
        //记得resize，关键
        s.resize(slow);
    }
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s,0,s.size()-1);
        int slow=0;
        for(int fast=0;fast<=s.size();++fast){
            if(fast == s.size() || s[fast] == ' '){
                reverse(s,slow,fast-1);
                slow = fast+1;
            }
        }
        return s;
    }
};
// @lc code=end

