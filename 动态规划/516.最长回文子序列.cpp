class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //这里的dp[i][j]表示i为起点，j为终点的情况下，最长的回文子序列
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //由于后面为了防止溢出＋1，所以这里需要先处理单个元素也作为回文加一
        for(int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for(int i = s.size()-1; i >= 0; i--) {
            //由于没有其他约束，+1防止溢出
            for(int j = i+1; j < s.size(); j++) {
                if(s[i] == s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.size()-1];
    }
};