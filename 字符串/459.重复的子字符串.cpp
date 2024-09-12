/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    void getNext(int* next,string& s){
        int j=-1;
        next[0]=j;
        for(int i=1;i<s.size();i++){
            while(j>=0 && s[i]!=s[j+1]){
                j=next[j];
            }
            if(s[i]==s[j+1]) j++;
            next[i]=j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0) return false;
        int next[s.size()];
        getNext(next,s);
        int len=s.size();
        //判断是否满足题目
        if(next[len-1]!=-1 && len%(len-next[len-1]-1)==0) return true;
        return false;
    }
};
// @lc code=end

