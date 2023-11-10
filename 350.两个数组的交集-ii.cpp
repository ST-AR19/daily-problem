/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        for(int num : nums1){
            ++mp[num];
        }
        vector<int> res;
        for(int num : nums2){
            if(mp[num]){
                //如果在mp中找到了num则说明这个num是两个数组的交集
                //则将num加入到答案中，同时减少mp中num的值
                //当mp中的num先减到0的时候，则说明num在nums1中的数量更少
                res.emplace_back(num);
                --mp[num];
                if(mp[num] == 0) mp.erase(num);
            }
        }
        return res;
    }
};
// @lc code=end

