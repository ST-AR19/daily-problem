/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        //变量的的提前声明
        unordered_map<char,int>tmap,smap;
        int left=0,right=0,flag=0;
        string res=s+"initial";
        //tmap整理
        for(auto temp:t) ++tmap[temp];
        //本体
        for(;right<s.size();++right){
            //整理smap
            ++smap[s[right]];
            //判断是否满足t字符串
            if(smap[s[right]] <= tmap[s[right]]) ++flag;
            //满足条件时删除冗余元素
            while(tmap[s[left]] < smap[s[left]] && left < right){
                --smap[s[left]];
                left++;
            }
            //确定答案
            if(flag == t.size() && right-left+1 < res.size())
                res = s.substr(left,right-left+1);
        }
        //三元运算符输出答案
        return res == s+"initial" ? "" : res;
    }
};
// @lc code=end

