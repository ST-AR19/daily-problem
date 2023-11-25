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
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
                long long num1=result.top();
                result.pop();
                long long num2=result.top();
                result.pop();
                if(tokens[i]=="+") result.push(num2 + num1);
                if(tokens[i]=="-") result.push(num2 - num1);
                if(tokens[i]=="*") result.push(num2 * num1);
                if(tokens[i]=="/") result.push(num2 / num1);
            }else{
                result.push(stoll(tokens[i]));
            }
        }
        return result.top();
    }
};
// @lc code=end

