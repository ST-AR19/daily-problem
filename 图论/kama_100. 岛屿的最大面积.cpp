#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int midResult=0;

void DFS(int n, int m, vector<vector<int>> area, vector<vector<bool>> &visited, int x, int y) {
    for(int i = 0; i < 4; i++) {
        int nextX = x+dir[i][0];
        int nextY = y+dir[i][1];
        if(nextX<0 || nextY<0 || nextX>=n || nextY >=m) continue;
        if(!visited[nextX][nextY] && area[nextX][nextY]) {
            visited[nextX][nextY] = true;
            midResult++;
            DFS(n,m,area,visited,nextX,nextY);
        }
    }
}

int main() {
    int n,m;
    cin >>n>>m;
    vector<vector<int>> area(n, vector<int>(m,0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >>area[i][j];
        }
    }
    
    int result=0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && area[i][j]) {
                visited[i][j]=true;
                midResult = 1;
                DFS(n,m,area,visited,i,j);
                result=max(result, midResult);
            }
        }
    }
    
    cout <<result;
}