/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    //406和135的核心在于先考虑其中的一个条件
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> que;
        for(int i = 0; i < people.size(); i++){
            int add = people[i][1];
            que.insert(que.begin() + add, people[i]);
        }
        return que;
    }
};
// @lc code=end

