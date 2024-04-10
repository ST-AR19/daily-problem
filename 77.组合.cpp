/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int n, int k, int start){
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = start; i <= n; i++){
            path.push_back(i);
            //使用i+1以免出现重复组合
            backTracking(n, k, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result;
    }
};
// @lc code=end

