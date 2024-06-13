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
        //单调栈(行计算)
        int result=0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < height.size(); i++){
            while(!st.empty() && height[i] > height[st.top()]) {
                int temp = st.top();
                st.pop();
                //关键 由于我们设置的这个单调栈的性质
                //栈中当前元素的下一个元素是它的左边界，而进了这个while则说明找到了它的右边界
                //此时便可以计算左右边界之间的面积即是可以接到的雨水多少
                //这里对于相邻且相同高度的处理逻辑是计算面积为0
                if (!st.empty()) 
                result += (min(height[i], height[st.top()])-height[temp]) * (i-st.top()-1);
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

