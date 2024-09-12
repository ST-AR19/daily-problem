/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size() , 0);
        int flag = nums.size() - 1;
        for(int i = 0 , j = nums.size() - 1 ; flag >= 0;){
            if(nums[i] * nums[i] < nums[j] * nums[j]){
                result[flag--] = nums[j] * nums[j];
                j--;
            }else{
                result[flag--] = nums[i] * nums[i];
                i++;
            }
        }
        return result;
    }
};
// @lc code=end

