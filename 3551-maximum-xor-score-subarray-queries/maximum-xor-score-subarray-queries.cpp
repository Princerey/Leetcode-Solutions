class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>dp(n, vector<int>(n));
        for(int i=0;i<n;i++)dp[i][i]=nums[i];
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                dp[i][j]=dp[i][j-1]^dp[i+1][j];
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                dp[i][j]=max(dp[i][j], max(dp[i][j-1],dp[i+1][j]));
            }
        }
        for(auto q:queries)ans.push_back(dp[q[0]][q[1]]);
        return ans;
    }
};