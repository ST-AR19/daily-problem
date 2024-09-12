/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(string s, int startIndex, int endIndex){
        for(int i=startIndex, j=endIndex; i<j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    void backTracking(string s, int startIndex){
        if(startIndex >= s.size()){
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i<s.size(); i++){
            if(isPalindrome(s, startIndex, i)){
                string temp = s.substr(startIndex, i-startIndex+1);
                path.push_back(temp);
            }else continue;
            backTracking(s, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        backTracking(s, 0);
        return result;
    }
};
// @lc code=end

