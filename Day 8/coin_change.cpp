class Solution {
public:
    int coinChange(vector<int>& coins, int x) {
        int m = coins.size();
        vector<vector<int>> dp(m+1, vector<int>(x+1, x+1));

        for(int i = 0; i <= m; i++) {
            dp[i][0] = 0; 
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= x; j++) {
                if(j - coins[i-1] >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j-coins[i-1]] + 1);
                }
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
        }

        return dp[m][x] > x ? -1 : dp[m][x];
    }
};