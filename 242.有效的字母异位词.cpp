/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int wordFrequency[26]={0};
        for(int i=0;i<s.size();i++){
            wordFrequency[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            wordFrequency[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(wordFrequency[i] != 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

