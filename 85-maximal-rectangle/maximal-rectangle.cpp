class Solution {
public:
    int lra(vector<int>& h) {
        int n = h.size(), m = *max_element(h.begin(), h.end()), ans = h[0];
        vector<int> p(m + 1, 0), c(m + 1, 0);
        for(int i = h[0]; i > 0; i--) c[i] = i;
        for(int i = 1; i < n; i++)
        {
            p = c;
            fill(c.begin(), c.end(), 0);
            for(int j = h[i]; j > 0; j--)
            {
                ans = max(c[j] = p[j] + j, ans);
            }
        }

        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> v(n, vector<int> (m, 0));

        for(int i = 0; i < m; i++) v[0][i] = mat[0][i] - '0';
        int ans = lra(v[0]);

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(mat[i][j] - '0') v[i][j] = v[i - 1][j] + 1;
            }
            ans = max(ans, lra(v[i]));
        }

        return ans;
    }
};