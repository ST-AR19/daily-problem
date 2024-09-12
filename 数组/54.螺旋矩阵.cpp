/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //设置变量
        vector<int> res;
        int startX=0,startY=0;
        int boundaryLimit=1;
        int count=0;
        int row=matrix.size();
        int column=matrix[0].size();
        //本体
        while(count < row*column){
            int i=startX,j=startY;
            //提前放在这以防止超过二维数组界限
            if(count == row*column-1){
                res.push_back(matrix[startX][startY]);
                count++;
            }
            //走圈
            for(;j<column-boundaryLimit;j++){
                res.push_back(matrix[i][j]);
                count++;
            }
            for(;i<row-boundaryLimit;i++){
                res.push_back(matrix[i][j]);
                count++;
            }
            for(;j>startY;j--){
                res.push_back(matrix[i][j]);
                count++;
                if(count == row*column) break;//防止往回走
            }
            for(;i>startX;i--){
                res.push_back(matrix[i][j]);
                count++;
                if(count == row*column) break;//防止往回走
            }
            //为下一圈做准备
            startX++;
            startY++;
            boundaryLimit++;
        }
        return res;
    }
};
// @lc code=end

