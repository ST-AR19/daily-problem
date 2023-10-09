/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int first = 0;
        int last = 0;
        int length = INT32_MAX;
        int sum = 0;
        for(; last < nums.size() ; last++){
            sum += nums[last];
            while( sum >= target){
                int temp = last - first + 1;
                length = length > temp ? temp : length;
                sum -= nums[first++];
            }
        }
        return length = length == INT32_MAX ? 0 : length;
    }
};
// @lc code=end

