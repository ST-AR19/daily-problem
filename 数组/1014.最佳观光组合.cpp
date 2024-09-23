/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = 0;
        //将计算分成两部分
        int mx = values[0];
        for(int i = 1; i < values.size(); i++) {
            result = max(result, mx+values[i]-i);
            //一边遍历一遍维护其中一部分
            mx = max(mx, values[i]+i);
        }
        return result;
    }
};
// @lc code=end

