/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        vector<int>F;
        F.push_back(0);
        F.push_back(1);
        for(int i = 2; i <= n; i++){
            F.push_back(F[i-1]+F[i-2]);
            cout<<F[i]<<" ";
        }
        return F[n];
    }
};
// @lc code=end

