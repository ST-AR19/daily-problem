class Solution {
public:
    int numDistinct(string s, string t) {
        if(s == t) return 1;
        //有一个测试用例超过了long long 要用unsigned long long才行
        vector<vector<uint64_t>> dp(s.size()+1, vector<uint64_t>(t.size()+1, 0));
        for(int i = 0; i < s.size()+1; i++) dp[i][0] = 1;
        for(int i = 1; i < s.size()+1; i++) {
            for(int j = 1; j < t.size()+1; j++) {
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else dp[i][j] = dp[i-1][j];
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        return dp[s.size()][t.size()];
    }
};