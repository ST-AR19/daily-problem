class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.size() && !t.size()) return true;
        if(s.size() > t.size()) return false;
        vector<int> dp(t.size(), 0);
        if(t[0] == s[0]) dp[0] = 1;
        for(int i = 1; i < t.size(); i++) {
            dp[i] = dp[i-1];
            if(t[i] == s[dp[i-1]]) dp[i]++;
            //cout<<dp[i]<<" ";
        }
        if(dp[t.size()-1] == s.size()) return true;
        return false;
    }
};