
class Solution {
public:
int dp[1001][1001][2][2][2];
   int find(int index,int prev_index,int start,int mid,int end,vector<int>&a,int n)
   {

    if(start && mid && end)
    return 0;

     if(index>=n)
     return -1001;

     if(dp[index][prev_index][start][mid][end]!=-1)
     return dp[index][prev_index][start][mid][end];

     int take=-1;
     if(!start && !mid && !end)
     take=1+find(index+1,index,1,0,0,a,n);

     else if(start && !mid && !end && a[index]>a[prev_index])
    {
     
     take=max(1+find(index+1,index,1,0,0,a,n),1+find(index+1,index,1,1,0,a,n));
     
    }
     else if(start && mid && !end && a[index]<a[prev_index])
     {
       
            take=max(1+find(index+1,index,1,1,0,a,n),1+find(index+1,index,1,1,1,a,n));
     }
     int nottake=find(index+1,prev_index,start,mid,end,a,n);
     int ans=max(take,nottake);
     return dp[index][prev_index][start][mid][end]=ans;

   }
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        memset(dp,-1,sizeof(dp));
        return n-find(0,0,0,0,0,a,n);
    }
};