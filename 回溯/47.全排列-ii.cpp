/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, vector<bool> used){
        if(path.size() == nums.size()) result.push_back(path);
        for(int i = 0; i < nums.size(); i++){
            //这里的used[i-1] == true 也行，但效率不如false，false是在树层上去重，true是在树枝上去重
            if(i > 0 && used[i-1] == false  && nums[i] == nums[i-1]) continue;
            if(!used[i]){
                used[i] = true;
                path.push_back(nums[i]);
                backTracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return result;
    }
};
// @lc code=end

