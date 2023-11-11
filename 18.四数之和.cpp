/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return res;
        for(int i=0; i<=nums.size()-4; ++i){
            if(nums[i]>target && nums[i]>=0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<=nums.size()-3; ++j){
                if(nums[i]+nums[j]>=target && nums[j]>0) break;
                int left = j+1;
                int right = nums.size()-1;
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                while(left<right){
                    //设置为long型防止int溢出
                    if((long)nums[i]+nums[j]+nums[left]+nums[right]<target) ++left;
                    else if((long)nums[i]+nums[j]+nums[left]+nums[right]>target) --right;
                    else{
                        res.emplace_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(right>left && nums[right]==nums[right-1]) --right;
                        while(left<right && nums[left]==nums[left+1]) ++left;
                        --right;
                        ++left;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

