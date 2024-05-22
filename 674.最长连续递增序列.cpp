/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = -1;
        int result = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) result = max(result, i-start);
            else start = i-1;
        }
        return result;
    }
};
// @lc code=end

