/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        //对给的数组进行排序以方便找0值
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<=len-3;++i){
            int left = i+1;
            int right = len-1;
            //对开始的数字进行去重
            if(i>0 && nums[i]==nums[i-1]) continue;
            while(left<right){
                if(nums[i]+nums[left]+nums[right]<0) ++left;
                else if(nums[i]+nums[left]+nums[right]>0) --right;
                else{
                    res.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                    //对已经有了是组合进行去重
                    //使用while以防止出现两个以上的相同数
                    while(right>left && nums[right]==nums[right-1]) --right;
                    while(right>left && nums[left]==nums[left+1]) ++left;
                    --right;
                    ++left;
                }
            }
        }
        return res;
    }
};
// @lc code=end

