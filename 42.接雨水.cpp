/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        //双指针法的优化(列计算)
        /*vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        int result=0;
        //初始化
        maxLeft[0] = height[0];
        maxRight[height.size()-1] = height[height.size()-1];
        //寻找对于每一列的左右边界
        for(int i = 1; i < height.size(); i++){
            maxLeft[i] = max(maxLeft[i-1], height[i]);
        }
        for(int i = height.size()-2; i >= 0; i--){
            maxRight[i] = max(maxRight[i+1], height[i]);
        }
        //左右边界的最小值减去自身所在列的高度乘以列的宽度1，得到该位置能接到的雨水
        for(int i = 1; i < height.size()-1; i++){
            result += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return result;*/
        //双指针法的优化(行计算)
    }
};
// @lc code=end

