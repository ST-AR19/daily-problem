#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n,a,b;
    int pre=0;
    cin>>n;
    vector<int> vec(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
        //计算前缀和
        pre += vec[i];
        p[i] = pre;
    }
    
    while(cin>>a>>b){
        int result=0;
        result = p[b]-p[a]+vec[a];
        printf("%d\n",result);
    }
}