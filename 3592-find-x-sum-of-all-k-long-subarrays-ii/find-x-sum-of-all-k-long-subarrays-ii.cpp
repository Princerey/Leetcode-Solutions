typedef long long ll;
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;     
    }
    return a.second < b.second;
};
class myheap 
{
    public:
    set<pair<int, int>> hi;
    set<pair<int, int>> low;

    ll getsum(const pair<int, int>& a)
    {
        return (ll)a.first * (ll)a.second;
    }

    void erase(const pair<int, int>& a)
    {
        if (!hi.empty() && !low.empty())
        {
            if ( cmp(*low.rbegin(), a))
            {
                hi.erase(a);
                sum -= getsum(a);
            }
            else 
            {
                low.erase(a);
            }
        }
        else if(low.empty())
        {
            hi.erase(a);
            sum -= getsum(a);
        }
        else {
            low.erase(a);
        }
    }

    void insert(const pair<int, int>& a)
    {
        if (!hi.empty() && !low.empty())
        {
            if ( cmp(*low.rbegin(), a))
            {
                hi.insert(a);
                sum += getsum(a);
            }
            else 
            {
                low.insert(a);
            }
        }
        else 
        {
            hi.insert(a);
            sum += getsum(a);
        }
    }

    void ajust()
    {
        while (hi.size() < x && !low.empty())
        {
            hi.insert(*low.rbegin());
            sum += getsum(*low.rbegin());
            low.erase(*low.rbegin());
        }
        while (hi.size() > x)
        {
            low.insert(*hi.begin());
            sum -= getsum(*hi.begin());
            hi.erase(hi.begin());
        }
        if (!hi.empty() && !low.empty())
        {
            while (cmp(*hi.begin(), *low.rbegin()))
            {
                auto y = *hi.begin();
                auto x = *low.rbegin();
                hi.erase(y);
                sum -= getsum(y);
                low.erase(x);

                hi.insert(x);
                sum += getsum(x);
                low.insert(y);
            }
        }
    }

    void debug() 
    {
        cout << "hi " << endl; 
        for (auto& p : hi)
        {
            cout << p.first << "," << p.second << " ";
        }
        cout << endl;

        cout << "low " << endl; 
        for (auto& p : low)
        {
            cout << p.first << "," << p.second << " ";
        }
        cout << endl;
    }
    int x = 0;

    ll sum = 0;
};

class Solution {
public:
    myheap heap;
    unordered_map<int, int> mp;
    int k;
    void erase(int v)
    {
        heap.erase({mp[v], v});
        mp[v]--;
        if (mp[v] > 0)
        {
            heap.insert({mp[v], v});
        }
    }

    void insert(int v)
    {
        heap.erase({mp[v], v});
        mp[v]++;
        heap.insert({mp[v], v});
    }

    vector<long long> findXSum(vector<int>& nums, int k1, int x) {
        heap.x = x;
        k = k1;
        int n = nums.size();
        for (auto v : nums) {
            mp[v] = 0;
        }
        vector<ll> ans;
        for (int i = 0; i < n; i++)
        {
            if (i - k >= 0)
            {
                erase(nums[i - k]);
            }
            insert(nums[i]);
            heap.ajust();
            if (i + 1 >= k)
            {
                ans.push_back(heap.sum);
            }
        }
        return ans;

    }
};