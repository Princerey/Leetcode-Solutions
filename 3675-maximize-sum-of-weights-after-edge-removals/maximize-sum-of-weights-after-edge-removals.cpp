typedef long long ll;
class Solution {
public:
    vector<vector<pair<int, int>>> es;
    vector<vector<ll>> dp;
    int n;
    int k;
    ll dfs(int i, int j, int p, int pw)
    {
        if (dp[i][j] != LLONG_MIN) return dp[i][j];
        ll cur = 0;
        int ex = 0;
        if (j == 1 && p != -1)
        {
            ex  = 1;
        }
        if (es[i].size() - ex <= k)
        {
            for (auto&[y, w] : es[i])
            {
                if (y == p) continue;
                cur += w;
                cur += dfs(y, 0, i, w);
            }
            dp[i][j] = cur;
        } else 
        {
            int m = es[i].size();
            auto& e = es[i];
            vector<vector<ll>> arr(m, vector<ll>(2, 0));
            for (int x = 0; x < m; x++)
            {
                if (e[x].first == p)
                {
                    if (j == 0)
                    {
                        arr[x] = {0, -e[x].second};
                    }
                    else 
                    {
                        arr[x] = {0, 0};
                    }
                } 
                else
                {
                    arr[x][0] = dfs(e[x].first, 0, i , e[x].second) + e[x].second ;
                    arr[x][1] = dfs(e[x].first, 1, i , e[x].second);
                }
            }
            sort(arr.begin(), arr.end(), [](vector<ll>& a, vector<ll>& b){
                ll d1 = a[1] - a[0];
                ll d2 = b[1] - b[0];
                if (d1 != d2) return d1 > d2;
                return a[0] > b[0];
            });
            int m1 = m - k;
            for (int x = 0; x < arr.size(); x++)
            {
                if (x < m1)
                {
                    cur += arr[x][1];
                } else 
                {
                    cur += arr[x][0];
                }
            }
            dp[i][j] = cur;
        }
        return cur;
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k1) {\
        k = k1;
        n = edges.size();
        es.resize(n + 1);
        for (auto& e : edges)
        {
            int x = e[0];
            int y = e[1];
            int w = e[2];
            es[x].push_back({y, w});
            es[y].push_back({x, w});
        }
        dp = vector<vector<ll>>(n + 1, vector<ll>(2, LLONG_MIN));
        return dfs(0, 0, -1, 0);
    }
};