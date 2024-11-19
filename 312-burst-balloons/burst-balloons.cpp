class Solution {
    int solve(vector<int>& nums , vector<vector<int>>& dp , int i , int j){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k <= j ; k++){
             int left = i >= 1  ? nums[i - 1] : 1 , right = j + 1 < nums.size() ? nums[j + 1] : 1;
             dp[i][j] = max(dp[i][j] , solve(nums , dp , i , k - 1)  + left * nums[k] * right + solve(nums , dp , k + 1 , j));
        }
        return dp[i][j];
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return solve(nums , dp , 0 , n - 1);
    }
};