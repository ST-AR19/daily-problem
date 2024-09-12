class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j]表示i为起点，j为终点的子串是否为回文串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for(int i = s.size()-1; i >= 0; i--) {
            //dp[i][j]会依赖于dp[i+1][j-1]，因此遍历顺序是从左到右，从下到上
            for(int j = i; j < s.size(); j++) {
                //这里实际上有多种情况，首先s[i]不等于s[j]肯定不符合题意
                //在s[i]等于s[j]的大前提下，i和j相等或者相差1是符合的
                //再来即表示被i和j所包裹的区域是否符合题意了
                if(s[i] == s[j] && (j - i < 2 || dp[i+1][j-1])){
                    result++;
                    dp[i][j] = true;
                }
            }
        }
        return result;
    }
};