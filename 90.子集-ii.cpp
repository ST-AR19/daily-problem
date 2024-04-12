/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& nums, int startIndex){
        result.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            if(i > startIndex && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            backTracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backTracking(nums, 0);
        return result;
    }
};
// @lc code=end

