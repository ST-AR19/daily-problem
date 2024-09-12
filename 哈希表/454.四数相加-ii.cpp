/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>sum;//数组nums1和nums2的出现的和的所有结果
        for(int i : nums1){
            for(int j : nums2){
                ++sum[i+j];
            }
        }
        int ans = 0;
        for(int i : nums3){
            for(int j : nums4){
                if(sum.find(0-i-j) != sum.end()){
                    ans += sum[0-i-j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

