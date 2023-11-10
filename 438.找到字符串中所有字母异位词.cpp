/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.size(), plen = p.size();
        if(slen < plen){
            return vector<int>();
        }
        vector<int> ans;
        vector<int> record(26);
        //通过判断是否有不满足条件的单词来判断是否应该将当前加入答案
        int differ = 0;
        for(int i=0;i<plen;i++){
            ++record[p[i]-'a'];
            --record[s[i]-'a'];
        }
        //先提前判断前plen是否符合条件
        for(int i=0;i<26;i++){
            if(record[i] != 0) ++differ;
        }
        if(differ == 0){
            ans.emplace_back(0);
        }
        for(int i=0;i<slen-plen;++i){ 
            //i代表的是在窗口中被删除的元素，不在当前查找的对应字母异位词
            //于是对于i的判断必须要在前面
            if(record[s[i]-'a'] == 0) ++differ;
            else if(record[s[i]-'a'] == -1) --differ;
            ++record[s[i]-'a'];
            //plen+i即新加入窗口的词
            if(record[s[plen+i]-'a'] == 0) ++differ;
            else if(record[s[plen+i]-'a'] == 1) --differ;
            --record[s[plen+i]-'a'];
            //由于i代表的是前一个窗口的第一个元素，所以加入数组的是第i+1个单位
            if(differ == 0) ans.emplace_back(i+1);
        }
        return ans;
    }
};
// @lc code=end

