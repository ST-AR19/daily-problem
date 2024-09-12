/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //mp用来存储遍历过的数据
        unordered_map<int,int> mp;
        int i=0;
        for(;i<nums.size();++i){
            auto it = mp.find(target - nums[i]);
            if(it != mp.end()){
                //注意返回的类型是vector
                return {it->second, i};
            }
            //使用pair来将这两个值作为一个单元存储在一起
            mp.insert(pair<int,int>(nums[i],i));
        }
        return {};
    }
};
// @lc code=end

