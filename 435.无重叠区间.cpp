/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int result=0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]){
                result++;
                intervals[i][1] = min(intervals[i][1], intervals[i-1][1]);
            }
        }
        return result;
    }
};
// @lc code=end

