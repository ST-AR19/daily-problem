/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
            //去重精髓，排除candidates数组中数值相同的数字的结果重复出现
            if(i > startIndex && candidates[i] == candidates[i-1]) continue;
            path.push_back(candidates[i]);
            target -= candidates[i];
            backTracking(candidates, target, i+1);
            target += candidates[i];
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0);
        return result;
    }
};
// @lc code=end

