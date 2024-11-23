class Solution {
public:
    void pal(char* s, int k, vector<int>& v, int parity) { // 1 = even, 0 = odd
        int prev_c = 0;
        int prev_r = 0;
        for(int i = 0; i < k - parity; i++) {
            int offset = parity;
            if(i <= prev_c + prev_r - parity) {
                v[i] = v[(prev_c << 1) - i];
                if(v[i] == prev_c + prev_r - i) offset = v[i];
                else {
                    v[i] = min(v[i], prev_c + prev_r - i);
                    continue;
                }
            }
            int m = i - offset + parity;
            int n = i + offset;
            while(m > -1 && n < k && s[m] == s[n]) {
                m--;
                n++;
            }
            prev_c = i;
            prev_r = i - m - 1 + parity;
            v[i] = prev_r;
        }
    }
    void dfs(int k, char* r, vector<vector<int>>& t, string& s, vector<int>& l, vector<int>& p, int& c) {
        for(int i : t[k]) {
            dfs(i, r, t, s, l, p, c);
            l[k] += l[i];
        }
        r[c] = s[k];
        p[k] = c;
        c++;
    }
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> tree(n, vector<int>());
        for(int i = 1; i < n; i++) tree[parent[i]].push_back(i);
        for(vector<int>& v : tree) sort(v.begin(), v.end());
        vector<int> len(n, 1);
        vector<int> pos(n, 0);
        int c = 0;
        char all[n];
        dfs(0, all, tree, s, len, pos, c);
        vector<int> even(n - 1, 0);
        vector<int> odd(n, 0);
        pal(all, n, even, 1);
        pal(all, n, odd, 0);
        vector<bool> result(n, false);
        for(int i = 0; i < n; i++) result[i] = (len[i] % 2 ? odd : even)[pos[i] - len[i] / 2] >= len[i] / 2;
        return result;
    }
};