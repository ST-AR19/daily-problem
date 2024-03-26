/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> result;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-"|| tokens[i] == "*" || tokens[i] == "/"){
                long long int num1 = result.top();
                result.pop();
                long long int num2 = result.top();
                result.pop();
                if(tokens[i] == "+") result.push(num1+num2);
                if(tokens[i] == "-") result.push(num1-num2);
                if(tokens[i] == "*") result.push(num1*num2);
                if(tokens[i] == "/") result.push(num1/num2);
            }
            else result.push(stoll(tokens[i]));
        }
        return result.top();
    }
};
// @lc code=end

