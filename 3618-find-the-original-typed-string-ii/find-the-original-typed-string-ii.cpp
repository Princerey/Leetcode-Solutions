class Solution {
public:
    const int mod = 1e9 + 7;
    int possibleStringCount(string& s, int k) {
        vector<int> v;
        int n = s.length();
        int i = 0;
        while (i < n) {
            int count = 1;
            while (i + 1 < n && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            v.push_back(count);
            i++;
        }
        n = v.size();
        long long total = 1;
        for (int& x : v) {
            total = (total * x) % mod;
        }
        if (n >= 2000) {
            return total;
        }
        vector<vector<int>> dp(n, vector<int>(k, 0));
        for (int sum = 1; sum <= v[0] && sum < k; sum++) {
            dp[0][sum] = 1;
        }
        for (int sum = 1; sum < k; sum++) {
            dp[0][sum] = (dp[0][sum - 1] + dp[0][sum]) % mod;
        }
        for (int i = 1; i < n; i++) {
            for (int sum = 1; sum < k; sum++) {
                int j = min({v[i], sum, k - 1});
                dp[i][sum] = dp[i - 1][sum - 1];
                if (sum - j - 1 >= 0) {
                    dp[i][sum] = (dp[i][sum] - dp[i - 1][sum - j - 1] + mod) % mod;  
                }
            }
            for (int sum = 1; sum < k; sum++) {
                dp[i][sum] = (dp[i][sum - 1] + dp[i][sum]) % mod;
            }
        }
        return (total - dp[n-1][k-1] + mod) % mod;
    }
};
