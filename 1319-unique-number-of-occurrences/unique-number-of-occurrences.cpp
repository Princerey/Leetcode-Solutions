class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> ans;
        for (int i = 0; i < arr.size(); i++) {
            ans[arr[i]]++;
        }
        set<int> freq;
        for (auto it : ans) {
            if (freq.find(it.second) != freq.end()) {
                return false;
            }
            freq.insert(it.second);
        }
        return true;
    }
};