class Solution {
public:
    int solve(int ind, int prevwidth, int prevheight, vector<vector<int>> &envelopes, int n)
{
    if (ind >= n)
    {
        return 0;
    }
    int nonpick = 0 + solve(ind + 1, prevwidth, prevheight, envelopes, n);
    int pick = 0;
    if (envelopes[ind][0] > prevwidth and envelopes[ind][1] > prevheight)
    {
        pick = 1 + solve(ind + 1, envelopes[ind][0], envelopes[ind][1], envelopes, n);
    }
    return max(pick, nonpick);
}

static bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }

    return a[0] < b[0];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), cmp);
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        int val = envelopes[i][1];
        int index = lower_bound(temp.begin(), temp.end(), val) - temp.begin();

        if (index >= temp.size())
        {
            temp.push_back(val);
        }
        else
        {
            temp[index] = val;
        }
    }
    return temp.size();
}
};