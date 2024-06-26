#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
/*void DFS(int n, int m, vector<vector<int>> board, vector<vector<bool>> &visited, int curX, int curY) {
    for(int i = 0; i < 4; i++) {
        int nextX = curX + dir[i][0];
        int nextY = curY + dir[i][1];
        //cout<<curX<<" "<<curY<<endl;
        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
        if(!visited[nextX][nextY] && board[nextX][nextY]){
            visited[nextX][nextY] = true;
            DFS(n, m, board, visited, nextX, nextY);
        }
    }
    return;
}*/
void BFS(int n, int m, vector<vector<int>> board, vector<vector<bool>> &visited, int curX, int curY) {
    queue<pair<int, int>> que;
    que.push({curX, curY});
    visited[curX][curY] = true;
    while(!que.empty()) {
        pair<int, int> cur=que.front();
        que.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i = 0; i < 4; i++) {
            int nextX = x + dir[i][0];
            int nextY = y + dir[i][1];
            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
            if(!visited[nextX][nextY] && board[nextX][nextY]) {
                que.push({nextX, nextY});
                visited[nextX][nextY] = true;
            }
        }
    }
}
    

int main() {
    int n,m;
    cin >>n>>m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >>board[i][j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int result=0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && board[i][j]) {
                result++;
                visited[i][j]=true;
                //DFS(n, m, board, visited, i, j);
                BFS(n, m, board, visited, i, j);
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    
    cout <<result;
    return 0;
}