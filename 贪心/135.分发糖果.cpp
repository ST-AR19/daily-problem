/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> cnt(ratings.size(), 1);
        for(int i = 0; i < ratings.size()-1; i++){
            if(ratings[i] < ratings[i+1]) cnt[i+1] = cnt[i] + 1;
        }
        for(int i = ratings.size()-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]) cnt[i] = max(cnt[i], cnt[i+1]+1);
        }
        int result=0;
        for(int i = 0; i < ratings.size(); i++){
            result += cnt[i];
        }
        return result;
    }
};
// @lc code=end

