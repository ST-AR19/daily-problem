/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = {0};
        for(int i = 0; i < s.size(); i++) hash[s[i]-'a'] = i;
        int max = hash[s[0]-'a'];
        vector<int> result;
        //设置为-1是因为整体是一个左开右闭的区间，除了第一个区间，所以设置为-1以加上s[0]
        int pre=-1;
        for(int i = 0; i < s.size(); i++){
            if(hash[s[i]-'a'] > max) max=hash[s[i]-'a'];
            if(max == i) {
                result.push_back(max-pre);
                pre = max;
            }
        }
        return result;
    }
};
// @lc code=end

