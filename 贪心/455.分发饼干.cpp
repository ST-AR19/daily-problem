/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result=0;
        for(int i = 0; i < s.size(); i++){
            if(result < g.size() && s[i] >= g[result])
                result++;
        }
        return result;
    }
};
// @lc code=end

