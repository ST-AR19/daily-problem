/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int half = left + (right - left) / 2;
            if(nums[half] < target){
                left = half + 1;
            }else if(nums[half] > target){
                right = half - 1;
            }else{
                int temp = half;
                left = half;
                right = temp;//防止left和right的值一开始不是target
                while(half > 0 && nums[half] == nums[half - 1]){
                    half--;//要先加减再赋值
                    left = half;
                }
                while(temp < nums.size() - 1 && nums[temp] == nums[temp + 1]){
                    temp++;
                    right = temp;
                }
                return vector<int>{left, right};
            }
        }
        return vector<int>{-1, -1};
    }
};
// @lc code=end

