/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, map<string, int>> targetPlace;
    bool backTracking(vector<string>& result, int ticketNum){
        if(result.size() == ticketNum + 1) {
            return true;
        }
        for(pair<const string, int>& target : targetPlace[result[result.size()-1]]){
            if(target.second > 0){
                result.push_back(target.first);
                target.second--;
                if(backTracking(result, ticketNum)) return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;
        for(const vector<string>& temp : tickets){
            targetPlace[temp[0]][temp[1]]++;
        }
        result.push_back("JFK");
        backTracking(result, tickets.size());
        return result;
    }
};
// @lc code=end

