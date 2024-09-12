/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int j = 0; j < nums.size(); j++){
                //在测试样例的遍历过程中有超过最大int的累加和
                //但这个中间过程不影响最终结果，因此过滤掉这个中间过程就好了
                if(i >= nums[j] && dp[i] < INT_MAX - dp[i-nums[j]]){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end

