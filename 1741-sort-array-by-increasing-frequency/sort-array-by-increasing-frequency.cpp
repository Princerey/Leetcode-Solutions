class Solution {
public:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        int t[201];
        memset(t, 0, sizeof(t));
        for(int i = 0; i<n; i++){
            if(nums[i] == 0) t[0]++;
            
            if(nums[i] < 0){
                t[abs(nums[i])]++;
            }
            else if(nums[i] > 0){
                t[100 + nums[i]]++;
            }
        }
        vector<pair<int,int>> freq;
        
        for(int i = 0; i<=200; i++){
            
            if(t[i] == 0) continue;
            
            if(i == 0) freq.push_back({0, t[i]});
            
            if(t[i] > 0 && i <= 100 && i > 0){
                freq.push_back({-i, t[i]});
            }
            
            else if (i > 100){
                freq.push_back({i - 100, t[i]});
            }
        }
        sort(freq.begin(), freq.end(), compare);

        vector<int> result;
        for(auto& [num, fr]: freq){
            while(fr--){
                result.emplace_back(num);
            }
        }
        return result;
    }
};