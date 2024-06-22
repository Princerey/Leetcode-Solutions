class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> st;
        sort(nums.begin(), nums.end());   
        for(int i = 0; i < n - 2; i++)
        {
            int need = -nums[i]; 
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                if(nums[l] + nums[r] < need)
                    l++;
                else if(nums[l] + nums[r] > need)
                    r--;
                else
                {
                    st.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }     
        vector<vector<int>> ans;
        for(auto it : st)
            ans.push_back(it);    
        return ans;
    }
};