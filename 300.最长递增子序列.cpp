/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //特殊情况，由于下面for循环是先从1开始的，所以需要特判
        if(nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 1);
        int result=0;
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                //直接赋值会出问题，反正是求最大使用max找最大就行了
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};
// @lc code=end

