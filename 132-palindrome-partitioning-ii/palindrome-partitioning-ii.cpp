class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            for(int j = i; j >= 0; j--) {
                if(s[i] == s[j] && (i - j <= 1 || isPalindrome[j+1][i-1])) {
                    isPalindrome[j][i] = true;
                }
            }
        }

        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int i = 0 ; i < n ; i++){
            if(isPalindrome[0][i]) {
                dp[i] = 0;
            } else {
                int mini = INT_MAX;
                for(int j = 0; j < i; j++) {
                    if(isPalindrome[j+1][i]) {
                        mini = min(mini, dp[j] + 1);
                    }
                }
                dp[i] = mini;
            }
        }
        return dp[n-1];
    }
};