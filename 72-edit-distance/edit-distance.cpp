class Solution {
public:
    int f(int i,int j, string s1,string s2,vector<vector<int>>&dp){
        if(i < 0)return j+1;
        if(j < 0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i] == s2[j])return dp[i][j] = f(i-1,j-1,s1,s2,dp);
        int del = 1 + f(i,j-1,s1,s2,dp);
        int update = 1 + f(i-1,j,s1,s2,dp);
        int replace = 1 + f(i-1,j-1,s1,s2,dp);
        return dp[i][j] = min(del,min(update,replace));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int> (word2.length(),-1));
        return f(word1.length()-1,word2.length()-1,word1,word2,dp);
    }
};