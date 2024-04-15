/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;
    void backTracking(vector<string>& board, int n, int rows){
        if(rows == n) {
            result.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++){
            if(isValid(board, rows, i, n)){
                board[rows][i] = 'Q';
                backTracking(board, n, rows+1);
                board[rows][i] = '.';
            }
        }
        return;
    }
    bool isValid(vector<string> board, int rows, int cols, int n){
        //同列
        for(int i = 0; i < rows; i++){
            if(board[i][cols] != '.') return false;
        }
        //45度斜角
        for(int i = rows-1, j = cols-1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] != '.') return false;
        }
        //135度斜角
        for(int i = rows-1, j = cols+1; i >= 0 && j < n; i--, j++){
            if(board[i][j] != '.') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTracking(board, n, 0);
        return result;
    }
};
// @lc code=end

