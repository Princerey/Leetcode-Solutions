typedef long long ll;
class agg
{
    public:
    agg()
    {
        arr = vector<int>(4, 0);
    }
    vector<int> arr;
    int index(int x)
    {
        if (x == 2) return 0;
        else if (x == 3) return 1;
        else if (x == 5) return 2;
        else if (x == 7) return 3;
        return -1;
    }
    pair<int, int> convert(int a)
    {
        switch (a)
        {
            case 0:
            case 1:
                return {-1, -1};
            case 2:
                return {2, 1};
            case 3:
                return {3, 1};
            case 4:
                return {2, 2};
            case 5:
                return {5, 1};
            case 7:
                return {7, 1};
            case 8:
                return {2, 3};
            case 9:
                return {3, 2};
        }
        return {-1, -1};
    }
    void add(int a)
    {
        if (a == 6)
        {
            in(2, 1);
            in(3, 1);
        } else 
        {
            auto[x, y] = convert(a); 
            in(x, y);
        }
    }
    void rm(int a)
    {
        if (a == 6)
        {
            de(2, 1);
            de(3, 1);
        } 
        else 
        {
            auto[x, y] = convert(a); 
            de(x, y);
        }
    }

    void in(int a, int y)
    {
        int x = index(a);
        if (x == -1) return;
        arr[x] += y;
    }

    void de(int a, int y)
    {
        int x = index(a);
        if (x == -1) return;
        arr[x] -= y;
    }
};

class generator
{
    public:
    agg total;
    static constexpr int tb[4] = {2, 3, 5, 7};
    vector<int> gen(agg& prefix, int n, bool& res)
    {
        res = true;
        vector<int> ans;
        int j = n - 1;
        for (int i = 3; i >= 2; i--) 
        {
            int c = total.arr[i] - prefix.arr[i];
            if (c == 0) continue;
            int v = tb[i];
            if (i > 1) 
            {
                for (int x = 0; x < c; x++) 
                {
                    ans.push_back(v);
                }
            }
        }
        int b = total.arr[1] - prefix.arr[1];
        int a = total.arr[0] - prefix.arr[0];
        {
            int x = 2;
            int v = 3;
            while (b >= x)
            {
                int cc = 1;
                for (int k = 0; k < x; k++) cc = cc * v;
                ans.push_back(cc);
                b -= x;
            }
        }

        {
            int x = 3;
            int v = 2;
            while (a >= x)
            {
                int cc = 1;
                for (int k = 0; k < x; k++) cc = cc * v;
                ans.push_back(cc);
                a -= x;
            }
        }

        {
            if (a > 0 && b > 0)
            {
                int c = min(a, b);
                for (int i = 0; i < c; i++) {
                    ans.push_back(6);
                }
                a -= c;
                b -= c;
            }
            if (a > 0)
            {
                if (a == 2) ans.push_back(4);
                else ans.push_back(2);
            }
            if (b > 0)
            {
                if (b == 2) ans.push_back(9);
                else ans.push_back(3);
            }
        }
        if (ans.size() > n) {
            res = false;
            return ans;
        }
        while (ans.size() < n)
        {
            ans.push_back(1);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    int n;
    vector<int> nums;
    string tostring(vector<int>& a)
    {
        string cur;
        for (auto d : a) cur.push_back(d + '0');
        return cur;
    }
    string smallestNumber(string num, long long t) {
        for (auto c : num) nums.push_back(c - '0');
        n = nums.size();
        generator g;
        int arr[4] = {2, 3, 5, 7};
        int c0 = 0;
        for (int i = 0; i < 4; i++)
        {
            while ((t % arr[i]) == 0)
            {
                g.total.arr[i]++;
                t = t / arr[i];
            }
        }
        if (t != 1) return "-1";

        agg prefix;
        for (auto d : nums) {
            prefix.add(d);
            if (d == 0) 
            {
                c0++;
            }
        }
        bool mt = true;
        for (int i = 0; i < 4; i++)
        {
            if (g.total.arr[i] > prefix.arr[i]) 
            {
                mt = false;
            }
        }
        if (mt && c0 == 0)
        {
            return num;
        }
        
        for (int i = n - 1; i >= 0; i--)
        {
            prefix.rm(nums[i]);
            int l = n - i;
            int d = nums[i];
            if (d == 0) c0--;
            if (c0 > 0) continue;
            for (int x = d + 1; x <= 9; x++)
            {
                prefix.add(x);
                bool res = false;
                auto vec = g.gen(prefix, l - 1, res);
                prefix.rm(x);
                if (res == false) continue;
                vector<int> ans = nums;
                ans[i] = x;
                int l = n - 1;
                for (int j = vec.size() - 1; j >= 0; j--)  
                {
                    ans[l] = vec[j];
                    l--;
                } 
                return tostring(ans);
            }
        }

        for (int l = n + 1; l <= max(60, n + 1); l++)
        {
            bool res = false;
            auto vec = g.gen(prefix, l, res);
            if (res)
            {
                return tostring(vec);
            }
        }

        return "-1";
    }
};