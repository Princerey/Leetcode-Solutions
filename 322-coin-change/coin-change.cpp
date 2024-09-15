class Solution {
private:
    long long dp[10001];
    long long dfs(long long amount, vector<int>& coins, long long target) {
        if (amount == target) {
            return 0;
        }

        if (amount > target) {
            return INT_MAX / 2;
        }

        if (dp[amount] != -1) {
            return dp[amount];
        }

        int result = INT_MAX;
        for (auto coin : coins) {
            int localResult = 1 + dfs(amount + coin, coins, target);
            if (result > localResult) {
                result = localResult;
            }
        }
        dp[amount] = result;
        return result;
    }


public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        long long result = dfs(0, coins, amount);
        if (result >= INT_MAX / 2) { return -1; }
        return result;
    }
};