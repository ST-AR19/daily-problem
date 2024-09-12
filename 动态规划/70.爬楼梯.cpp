/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};
//进阶问题
//你可以爬至多m (1 <= m < n)个台阶，输入数据包含两个正整数，
/*#include <iostream>;
#include <vector>;
using namespace std;
int main(){
    int n, m;
    while(cin>>n>>m){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j <= m; j++){
                if(i > j) dp[i] += dp[i-j];
            }
        }
        cout<<dp[n]<<endl;
    }
}*/
// @lc code=end

