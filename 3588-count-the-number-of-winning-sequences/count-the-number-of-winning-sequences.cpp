typedef long long ll;
class Solution {
public:
    ll mod = 1e9+7;

    int dp[1005][2005][4];
    unordered_map<char, int> mp;

    ll point(ll move, ll alice){
        if(move==alice)return 0;
        if ((alice == 1 and move == 2) or (alice == 2 and move == 3) or
            (alice == 3 and move == 1))
            return 1;
        return -1;   
    }

    ll help(ll i, ll score, ll last, string &s){
        if(i==s.size())return ll(score)>0;

        if(dp[i][score+s.size()][last]!=-1)return dp[i][score+s.size()][last];

        ll ans=0;

        for(ll move = 1; move<=3; move++){
            if(move==last)continue;
            ans+= help(i+1, score+point(move, mp[s[i]]), move, s)%mod;
            ans%=mod;
        }

        return dp[i][score+s.size()][last]=ans;
    }

    int countWinningSequences(string s) {
        mp['F']=1;mp['W']=2;mp['E']=3;
        memset(dp, -1, sizeof(dp));
        return help(0,0,0,s)%mod;
    }
};