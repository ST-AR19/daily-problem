/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int k, int n, int startIndex){
        if(n == 0 && path.size() == k){
            result.push_back(path);
            return;
        }
        if(n < 0) return;
        for(int i = startIndex; i < 10; i++){
            n -= i;
            path.push_back(i);
            backTracking(k, n, i+1);
            path.pop_back();
            n += i;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(k, n, 1);
        return result;
    }
};
// @lc code=end

