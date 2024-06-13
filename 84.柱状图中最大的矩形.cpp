/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //双指针的优化(列计算)
        //记录左边第一个小于当前列高度的下标
        /*vector<int> minLeftIndex(heights.size(), 0);
        //记录右边第一个小于当前列高度的下标
        vector<int> minRightIndex(heights.size(), 0);
        int result=0;

        //先标记边界值，防止死循环
        //就算没找到合适的值，这样设置的初始值也不会导致计算出现问题
        minLeftIndex[0] = -1;
        for(int i = 1; i < heights.size(); i++) {
            int temp=i-1;
            //递归寻找到合适的值
            while(temp >= 0 && heights[temp] >= heights[i]) temp = minLeftIndex[temp];
            minLeftIndex[i] = temp;
        }

        minRightIndex[heights.size()-1] = heights.size();
        for(int i = heights.size()-2 ; i >= 0; i--) {
            int temp=i+1;
            while(temp < heights.size() && heights[temp] >= heights[i]) temp = minRightIndex[temp];
            minRightIndex[i] = temp;
        }

        for(int i = 0; i < heights.size(); i++) {
            //cout<<minRightIndex[i]<<" "<<minLeftIndex[i];
            result = max(result, heights[i]*(minRightIndex[i]-minLeftIndex[i]-1));
        }
        return result;*/
        stack<int> st;
        int result=0;
        //针对原本数组是递减数组，手动做一个左边界
        heights.insert(heights.begin(), 0);
        //针对原本数组是递增数组，手动做一个右边界
        heights.push_back(0);
        st.push(0);
        for(int i = 1; i < heights.size(); i++) {
            while(!st.empty() && heights[i] < heights[st.top()]) {
                int temp = st.top();
                st.pop();
                //由于设置的左右边界且数据大于等于0，实际上是不用考虑栈是否为空的情况的
                if(!st.empty()) {
                    //cout<<heights[temp]<<" "<<i-st.top()-1;
                    result = max(result, heights[temp]*(i-st.top()-1));
                }
            }
            st.push(i);
        }
        return result;
    }
};
// @lc code=end

