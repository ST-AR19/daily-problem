/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //创建一个二维无序映射
        unordered_map<string, vector<string>> mp;
        for(string str : strs){
            string key = str;
            //此时为str的副本key根据ascii排序
            //排完后字母异位词都会以a~z的顺序排列
            sort(key.begin(),key.end());
            //通常emplace_back比push_back的效率更高
            mp[key].emplace_back(str);
        }
        vector<vector<string>> res;
        for(auto it = mp.begin();it != mp.end();++it){
            //it是mp中的key(原本是unordered_map中的first
            //后面的second才是key所对应的值
            res.emplace_back(it->second);
        }
        return res;
    }
};
// @lc code=end

