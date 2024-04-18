/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int result=0;
        int sum=nums[0];
        int cur = 0;
        for(int i = 0; i < nums.size()-1; i++) {
            sum = max(sum, nums[i]+i);
            if( i == cur){
                result++;
                cur=sum;
            }
        }
        return result;   
    }
    
};
// @lc code=end

