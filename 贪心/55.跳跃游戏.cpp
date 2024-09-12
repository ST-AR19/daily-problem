/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if( nums.size() == 0) return true;
        int max = nums[0];
        for(int i = 1; i < nums.size() - 1; i++){
            cout<<max<<endl;
            if(i > max) return false;
            else {
                if(max < i+nums[i]) max = i+nums[i];
            }
        }
        return max >= nums.size()-1;
    }
};
// @lc code=end

