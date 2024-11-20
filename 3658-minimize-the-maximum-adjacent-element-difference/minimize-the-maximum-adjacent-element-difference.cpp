typedef long long ll;
class Solution {
public:
    int n;
    int md = 0;
    vector<pair<int, int>> dp1;
    vector<pair<int, int>> dp2;
    int a = INT_MAX;
    int minv = INT_MAX;
    int maxv = INT_MIN;

    pair<int, int> rang(int l, int r, int m)
    {
        return {r - m, l + m}; 
    }
    bool test(int m)
    {
        int x = a + m;

        int y1 = minv;
        int y2 = maxv;
        for (auto&[l, r] : dp1)
        {
            if (abs(x - l) <= m && abs(x - r) <= m) continue;
            auto r1 = rang(l, r, m);
            if (r1.second < r1.first) return false;
            y1 = max(y1, r1.first);
            y2 = min(y2, r1.second);
            if (y1 > y2) return false;
        }

        for (auto&[l, r] : dp2)
        {
            if (abs(x - l) <= m && abs(x - r) <= m) continue;
            if (x > l) 
            {
                if ((x - l) > m) return false;
                pair<int, int> r1 = {max(x , r - m), min(x + m, r + m)};
                if (r1.second < r1.first) return false;
                y1 = max(y1, r1.first);
                y2 = min(y2, r1.second);
                if (y1 > y2) return false;
            } 
            else 
            {
                // both y
                auto r1 = rang(l, r, m);
                if (r1.second < r1.first) return false;
                y1 = max(y1, r1.first);
                y2 = min(y2, r1.second);
                if (y1 > y2) return false;
            }
        }
        if (y1 > y2) return false;
        return true;
    }
    void push(vector<pair<int, int>>& cur, int x, int y)
    {
        cur.push_back({min(x, y), max(x, y)});
    }
    int minDifference(vector<int>& nums) {
        n = nums.size();
        int pre = -1;
        int last = -1;
        minv = INT_MAX;
        maxv = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                if (pre == -1) pre = nums[i];
                last = nums[i];

                if (i - 1 >= 0 && nums[i - 1] > 0)
                {
                    md = max(md, abs(nums[i] - nums[i - 1]));
                }

                minv = min(minv, nums[i]);
                maxv = max(maxv, nums[i]);
            }
        }
        if (last == -1) return 0;

        int i = 0;
        while (i < n)
        {
            if (nums[i] != -1) {
                pre = nums[i];
                i++;
                continue;
            }
            int cnt = 0;
            while (i < n && nums[i] == -1)
            {
                cnt++;
                i++;
            }
            int e = (i >= n) ? last : nums[i];
            if (cnt == 1)
            {
                a = min(pre, a);
                a = min(e, a);
                push(dp1, pre, e);
                // dp1.push_back({pre, e});
            }
            else 
            {
                a = min(pre, a);
                a = min(e, a);
                push(dp2, pre, e);
            }

        }
        if (dp1.empty() && dp2.empty()) return md;

        ll l = md;
        ll r = maxv - minv;
        ll ans = r;
        while (l <= r)
        {
            ll m = (l + r)/2;
            bool res = test(m);
            if (res)
            {
                ans = m;
                r = m - 1;
            }
            else 
            {
                l = m + 1;
            }
        }

        return ans;

    }
};