#include <iostream>
#include <vector>
#include <list>
using namespace std;
vector<vector<int>> result;
vector<int> temp;

//邻接矩阵
/*void DFS(vector<vector<int>> chart, int start, int n) {
    if(start == n) {
        result.push_back(temp);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(chart[start][i]) {
            temp.push_back(i);
            DFS(chart, i, n);
            temp.pop_back();
        }
    }
}

int main() {
    int m,n,s,t;
    //提交的时候在这里出错n和m写反了
    cin>>n>>m;
    vector<vector<int>> chart(n+1, vector<int>(n+1, 0));
    while(m--) {
        cin>>s>>t;
        chart[s][t]=1;
    }
    temp.push_back(1);
    DFS(chart, 1, n);
    if(result.size() == 0 ) cout<<-1<<endl;
    for(vector<int> &pa : result) {
        for(int i = 0; i < pa.size()-1; i++) {
            cout<<pa[i]<<" ";
        }
        cout<<pa[pa.size()-1]<<endl;
    }
    return 0;
}*/

//邻接表
void DFS(vector<list<int>> chart, int start, int n) {
    if(start == n) {
        result.push_back(temp);
        return;
    }
    for(int i : chart[start]){
        temp.push_back(i);
        DFS(chart, i, n);
        temp.pop_back();
    }
}

int main() {
    int n,m,s,t;
    cin >>n>>m;
    vector<list<int>> chart(n+1, list<int>(n+1, 0));
    while (m--) {
        cin >>s>>t;
        chart[s].push_back(t);
    }
    temp.push_back(1);
    DFS(chart, 1, n);

    if(result.size() == 0) cout<< -1 <<endl;
    for(vector<int> &pa : result) {
        for(int i = 0; i < result.size()-1; i++) {
            cout<<pa[i]<<" ";
        }
        cout<<pa[pa.size()-1]<<endl;
    }
}