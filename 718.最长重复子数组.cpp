/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //要比原来长度多1位来帮助计算
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int result = 0;
        //实际上的i、j对应的是数组1、2的i-1、j-1号下标
        //这样可以将数组元素遍历完，否则由于递推公式会少考虑数组的第一位(或者需要做特判)
        for(int i = 1; i <= nums1.size(); i++){
            for(int j = 1; j <= nums2.size(); j++){
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                //cout<<dp[i][j]<<" ";
                result = max(result, dp[i][j]);
            }
            //cout<<endl;
        }
        return result;
    }
};
// @lc code=end

