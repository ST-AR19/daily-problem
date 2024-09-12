/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int>& candidates, int target, int startIndex){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(target < 0) return;
        for(int i = startIndex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            target -= candidates[i];
            backTracking(candidates, target, i);
            target += candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backTracking(candidates, target, 0);
        return result;
    }
};
// @lc code=end

