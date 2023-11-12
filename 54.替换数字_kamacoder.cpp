#include<iostream>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int cnt = 0;
        int oldSize = s.size();
        for(int i=0;i<oldSize;++i){
            if(s[i]>='0' && s[i]<='9')
                cnt++;
        }
        s.resize(s.size() + cnt*5);
        int newSize = s.size();
        for(int i=newSize-1,j=oldSize; j<i; --i,--j){
            if(s[j]>='0' && s[j]<='9'){
                s[i] = 'r';
                s[i-1] = 'e';
                s[i-2] = 'b';
                s[i-3] = 'm';
                s[i-4] = 'i';
                s[i-5] = 'n';
                i-=5;
            }
        }
        cout<<s<<endl;
    }
}