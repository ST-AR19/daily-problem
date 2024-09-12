/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string result = to_string(n);
        //使用flag来记录从哪里开始改为9
        int flag = result.size();
        for(int i = result.size()-1; i > 0; i--){
            if(result[i-1] > result[i]){
                flag = i;
                result[i-1] -= 1;
            }
        }
        for(int i = flag; i < result.size(); i++){
            result[i] = '9';
        }
        return stoi(result);
    }
};
// @lc code=end

