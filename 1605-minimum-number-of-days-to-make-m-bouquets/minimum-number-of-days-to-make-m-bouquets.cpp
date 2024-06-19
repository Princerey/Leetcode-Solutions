class Solution {
    #define ll long long
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < 1ll * m * k) return -1;
        unordered_map<int, int> starts, ends;

        vector<pair<int, int>> temp(bloomDay.size());
        for(int i = 0; i < bloomDay.size(); ++i){
            temp[i].first = bloomDay[i];
            temp[i].second = i;
        }

        sort(temp.begin(), temp.end());
        int res = 0, i = 0, s, e;
        while(res < m){
            s = ends.count(temp[i].second - 1) ? ends[temp[i].second - 1] : temp[i].second;
            e = starts.count(temp[i].second + 1) ? starts[temp[i].second + 1] : temp[i].second;
            res += (e - s + 1) / k - (temp[i].second - s) / k - (e - temp[i].second) / k;
            ends[e] = s;
            starts[s] = e;
            i++;
        }
        return temp[i - 1].first;
    }
};