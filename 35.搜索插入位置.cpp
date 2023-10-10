/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = 0;
        while (left <= right){
            int half = left + (right - left) / 2;
            if(nums[half] < target){
                left = half + 1;
                result = half + 1;
            }else if(nums[half] > target){
                right = half - 1;
                result = half;
            }else{
                return half;
            }
        }
        return result; 
    }
};
// @lc code=end

