/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur = 0;
        int sum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            cur += gas[i]-cost[i];
            sum += gas[i]-cost[i];
            if(cur < 0){
                start = i+1;
                cur = 0;
            }
        }
        if(sum < 0) return -1;
        return start;
    }
};
// @lc code=end

