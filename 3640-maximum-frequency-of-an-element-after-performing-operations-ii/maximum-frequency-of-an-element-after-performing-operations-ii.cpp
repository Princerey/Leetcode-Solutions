
typedef long long ll;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end()); 
        set<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int mx=1;
        for(auto & it:st){
            int num=it;
            auto itu=upper_bound(nums.begin(),nums.end(),it); itu--;
            int up=itu-nums.begin();
            auto itl=lower_bound(nums.begin(),nums.end(),it);
            int lo=itl-nums.begin();
            int lon=lower_bound(nums.begin(),nums.end(),it-k)-nums.begin();
            int upn=(--upper_bound(nums.begin(),nums.end(),it+k))-nums.begin();
            mx=max(mx,(up-lo+1)+min(numOperations,upn-up+lo-lon));
            int ex=lower_bound(nums.begin(),nums.end(),it-2*k)-nums.begin();
            mx=max(mx,min(up-ex+1,numOperations));
        }
        return mx;
    }
};