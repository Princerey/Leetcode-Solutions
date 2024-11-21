class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumOfGoodSubsequences(vector<int>& v) {
        unordered_map<int, long long> cnt;
        unordered_map<int, long long> sum;
        int n = v.size();

        for (int i = 0; i < n; i++) {
            cnt[v[i]] = (cnt[v[i]] + 1) % MOD;
            int prev = v[i] - 1;
            int next = v[i] + 1;
            cnt[v[i]] = (cnt[v[i]] + cnt[prev] + cnt[next]) % MOD;
            sum[v[i]] = (sum[v[i]] + v[i]) % MOD;
            sum[v[i]] = (sum[v[i]] + sum[prev] + cnt[prev] * v[i] % MOD +
                         sum[next] + cnt[next] * v[i] % MOD) %
                        MOD;
        }

        long long ans = 0;
        for (auto it : sum) {
            ans = (ans + it.second) % MOD;
        }

        return ans;
    }
};