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
        vector<int> minLeftIndex(heights.size(), 0);
        vector<int> minRightIndex(heights.size(), 0);
        int result=0;

        minLeftIndex[0] = -1;
        for(int i = 1; i < heights.size(); i++) {
            int temp=i-1;
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
        return result;
    }
};
// @lc code=end

