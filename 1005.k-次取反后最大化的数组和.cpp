/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    static bool cmp(int a, int b){
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int result=0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 && k > 0){
                nums[i] *= -1;
                k--;
            }
            result += nums[i];
        }
        if(k % 2) result -= nums[nums.size()-1]*2;
        return result;
    }
};
// @lc code=end

