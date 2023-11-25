/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0) return false;
        stack<char> judge;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') judge.push(')');
            else if(s[i]=='{') judge.push('}');
            else if(s[i]=='[') judge.push(']');
            else if(judge.empty() || judge.top() != s[i]) return false;
            else judge.pop();
        }
        return judge.empty();
    }
};
// @lc code=end

