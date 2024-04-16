/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool backTracking(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.') continue;
                //艹 看了半天，原来这里少了少了个等号（k <= '9')
                for(char k = '1'; k <= '9'; k++){
                    if(isValid(i, j, k, board)){
                        board[i][j] = k;
                        if(backTracking(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool isValid(int rows, int cols, char value, vector<vector<char>> board){
        //同行
        for(int i = 0; i < 9; i++){
            if(board[rows][i] == value) return false;
        }
        //同列
        for(int j = 0; j < 9; j++){
            if(board[j][cols] == value) return false;
        }
        //同九宫格
        int startRows = (rows / 3) * 3;
        int startCols = (cols / 3) * 3;
        for(int i = startRows; i < startRows+3; i++){
            for(int j = startCols; j < startCols+3; j++){
                if(board[i][j] == value) return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backTracking(board);
        return;
    }
};
// @lc code=end

