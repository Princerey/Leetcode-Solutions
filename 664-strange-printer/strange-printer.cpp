class Solution {
public:
    int dp[102][102];
    int rec(int l,int r,string &s)
    {
        if(l>r)
        {
            return 0;
        }
        if(l==r)
        {
            return 1;
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        int aa=1+rec(l+1,r,s);
        for(int i=l+1;i<=r;i++){
            if(s[i]==s[l])
            {
                aa=min(aa,rec(l+1,i-1,s)+rec(i,r,s));
            }
        }
        return dp[l][r]=aa;
    }
    int strangePrinter(string s) {
        int n=s.length();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,s);
        
    }
};