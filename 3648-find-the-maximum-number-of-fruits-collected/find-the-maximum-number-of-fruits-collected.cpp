class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fr) {
        int sol = 0;
        int n = fr.size();

        for (int i = 0; i < n; i++) {
            sol += fr[i][i];
            fr[i][i] = 0;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[n-1][0] = fr[n-1][0];
        for (int j = 1; j <= n/2; j++) {
            for (int i = n-1; i >= (n-1-j); i--) {
                int op1 = (i-1 >= (n-1-j)+1)? fr[i][j] + dp[i-1][j-1] : 0;
                int op2 = fr[i][j] + dp[i][j-1];
                int op3 = (i+1 < n) ? fr[i][j] + dp[i+1][j-1] : 0;
                dp[i][j] = max({op1, op2, op3});
            }
        }
        for (int j = n/2 + 1; j < n; j++) {
            for (int i = n-1; i >= j; i--) {
                int op1 = fr[i][j] + dp[i-1][j-1];
                int op2 = fr[i][j] + dp[i][j-1];
                int op3 = (i+1 < n) ? fr[i][j] + dp[i+1][j-1] : 0;
                dp[i][j] = max({op1, op2, op3});
            }
        }
        sol += dp[n-1][n-1];
        
        dp[0][n-1] = fr[0][n-1];
        for (int i = 1; i <= n/2; i++) {
            for (int j = n-1; j >= (n-1-i); j--) {
                int op1 = (j-1 >= (n-1-i)+1)? fr[i][j] + dp[i-1][j-1] : 0;
                int op2 = fr[i][j] + dp[i-1][j];
                int op3 = (j+1 < n) ? fr[i][j] + dp[i-1][j+1] : 0;
                dp[i][j] = max({op1, op2, op3});
            }
        }
        for (int i = n/2 + 1; i < n; i++) {
            for (int j = n-1; j >= n-1-(n-1-i); j--) {
                int op1 = fr[i][j] + dp[i-1][j-1];
                int op2 = fr[i][j] + dp[i-1][j];
                int op3 = (j+1 < n) ? fr[i][j] + dp[i-1][j+1] : 0;
                dp[i][j] = max({op1, op2, op3});
            }
        }
        sol += dp[n-1][n-1];
       
        return sol;
    }
};