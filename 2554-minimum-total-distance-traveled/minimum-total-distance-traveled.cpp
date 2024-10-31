typedef long long LL;
const int N = 110;

/*
    dp:
        state repr:
            f[i][j][k]: distribute first i robots to first j factories, and jth factory used k of its quota
        
        transition:
            for k : 0 -> f[][1]
                f[i][j][k] = f[i-1][j][k-1]
                f[i][j][0] = f[i][j-1][k]
*/

class Solution {
    LL f[N][N][N];
public:
    long long minimumTotalDistance(vector<int>& rs, vector<vector<int>>& fs) {
        
        int n = rs.size(), m = fs.size();
        sort(rs.begin(), rs.end());
        sort(fs.begin(), fs.end());

        rs.insert(rs.begin(), 0);
        fs.insert(fs.begin(), vector<int>(2, 0));

        LL ans = LONG_LONG_MAX;

        memset(f, 0x3f, sizeof f);
        for (int j = 0; j <= m; ++ j)
        {
            f[0][j][0] = 0;
        }

        for (int i = 1; i <= n; ++ i) // 100
        {
            for (int j = 1; j <= m; ++ j) // 100
            {
                for (int k = 0; k <= fs[j-1][1]; ++ k)
                    f[i][j][0] = min(f[i][j][0], f[i][j-1][k]);
                for (int k = 1; k <= fs[j][1]; ++ k) // 100
                {
                    f[i][j][k] = min(f[i][j][k], f[i-1][j][k-1] + abs(rs[i] - fs[j][0]));
                    if (i == n)
                    {
                        if (f[i][j][k] > LONG_LONG_MAX / 2) continue;
                        ans = min(ans, f[i][j][k]);   
                    }
                }
            }
        }      

        return ans;
    }
};