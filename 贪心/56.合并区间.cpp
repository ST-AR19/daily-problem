/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(intervals[0][0]);
        int maxEdge = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            //检测当前数据左边界是否超过该范围最大右边界，如果没有则更新最大右边界
            if(intervals[i][0] <= maxEdge) {
                maxEdge = max(maxEdge, intervals[i][1]);
            }
            //如果超过，则说明不重叠，更新左右边界，压入答案
            else{
                path.push_back(maxEdge);
                result.push_back(path);
                path.clear();
                path.push_back(intervals[i][0]);
                maxEdge = intervals[i][1];
            }
        }
        //最后一个数据有更新但没有压入
        path.push_back(maxEdge);
        result.push_back(path);
        return result;
    }
};
// @lc code=end

