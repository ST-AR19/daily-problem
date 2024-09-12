/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    void getNext(int* next, string& s){
        int j=-1;
        next[0]=j;
        for(int i=1; i<s.size();i++){
            while(j>=0 && s[i]!=s[j+1]){
                j=next[j];
            }
            if(s[i] == s[j+1]) j++;
            next[i]=j;
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int next[needle.size()];
        getNext(next,needle);
        int j=-1;
        for(int i=0;i<haystack.size();i++){
            //回退之后是与下一位比较，仍然可能不相等，所以可能需要不止一次的回退
            while(j>=0 && haystack[i] != needle[j+1]){
                j=next[j];
            }
            if(haystack[i] == needle[j+1]) j++;
            if(j==(needle.size()-1)){
                return i-needle.size()+1;
            }
        }
        return -1;
    }
};
// @lc code=end

