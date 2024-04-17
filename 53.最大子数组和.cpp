/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Sum = 0;
        int result = nums[0];
        for(int i = 0; i < nums.size(); i++){
            Sum += nums[i];
            if(result < Sum) result = Sum;
            if(Sum <= 0) Sum = 0;
        }
        //这一个版本过了，但不对，有问题nums[i] > curSum 这一段，至少现在我是这么认为的
        /*int curSum = 0;
        int result = nums[0];
        for(int i = 0; i< nums.size(); i++){
            curSum += nums[i];
            if(nums[i] > curSum) curSum = nums[i];
            if(result < curSum) result = curSum;
        }*/
        return result;
    }
};
// @lc code=end

