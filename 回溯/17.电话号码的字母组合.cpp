/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    const string letterMap[10] = {
        "", "",
        "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz",
    };
public:
    vector<string> result;
    string path;
    void backTracking(string digits, int startIndex){
        if(startIndex == digits.size()){
            result.push_back(path);
            return;
        }
        int digit = digits[startIndex] - '0';
        string letters = letterMap[digit];
        for(int i=0; i<letters.size(); i++){
            path.push_back(letters[i]);
            backTracking(digits, startIndex+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        backTracking(digits, 0);
        return result;
    }
};
// @lc code=end

