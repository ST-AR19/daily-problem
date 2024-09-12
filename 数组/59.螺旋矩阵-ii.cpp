/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n,0));
        int startX=0,startY=0;
        int count = 1;
        int coundaryLimit = 1;
        int temp = n*n;
        while(count <= temp){
            int i=startX;
            int j=startY;
            //左闭右开转圈
            for(j=startY; j<n-coundaryLimit;j++)
                res[startX][j] = count++;
            for(i=startX; i<n-coundaryLimit;i++)
                res[i][j] = count++;
            for(;j>startY;j--) 
                res[i][j] = count++;
            for(;i>startX;i--)
                res[i][j] = count++;
            //为后续圈做准备
            startX++;
            startY++;
            coundaryLimit++;
            if(count == temp){
                res[n/2][n/2]=count;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

