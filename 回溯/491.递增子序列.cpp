/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, int startIndex){
        if(path.size() > 1) result.push_back(path);
        int used[210] = {0};
        for(int i = startIndex; i < nums.size(); i++){
            if((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1) continue;
            used[nums[i]+100] = 1;
            path.push_back(nums[i]);
            backTracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backTracking(nums, 0);
        return result;
    }
};
// @lc code=end

