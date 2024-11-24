class Solution {
public:
    int n;
    int solve(int i,int x, int oro, vector<int>& nums, int k, vector<vector<vector<int>>> &dp) {
        if (i >= n) {
            return x==k;
        }

        if (dp[i][x][oro] != -1) return dp[i][x][oro];

        bool take = 0, notTake = 0;

        if(x<k) take = solve(i+1,x+1,oro|nums[i], nums, k, dp);
        notTake = solve(i+1,x,oro,nums,k,dp);

        return dp[i][x][oro] = take + notTake;
    }

    int maxValue(vector<int>& nums, int k) {
        n = nums.size();
        vector<int> ds;
        vector<vector<vector<int>>> dp1(n+1,vector<vector<int>>(k+1, vector<int>(129,-1))); //prefix
        vector<vector<vector<int>>> dp2(n+1,vector<vector<int>>(k+1, vector<int>(129,-1))); //suffix
        solve(0,0,0,nums,k,dp1);
        reverse(nums.begin(),nums.end());
        solve(0,0,0,nums,k,dp2);

        int ans = 0;

        for(int i=k; i<=n-k; i++){
            for(int or1=0; or1<128; or1++){
                for(int or2=0; or2<128; or2++){
                    if(dp1[i][k][or1]==-1 || dp2[n-i][k][or2]==-1) continue;
                    if(dp1[i][k][or2] && dp2[n-i][k][or2]){
                        ans = max(ans, or1^or2);
                    }
                }
            }
        }

        return ans;
    }

};