/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res;
        unordered_set<int> num(nums1.begin(),nums1.end());
        for(int i:nums2){//for循环中这样写会自动遍历容器里的元素
            //在unordered_set容器中如果find函数没有找到，会返回到最后一个元素之后位置的迭代器
            //这个返回值和end方法的返回值一样
            if(num.find(i) != num.end()){
                res.insert(i);
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};
// @lc code=end

