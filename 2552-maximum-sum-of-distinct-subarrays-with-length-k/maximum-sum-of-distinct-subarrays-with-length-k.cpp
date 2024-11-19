class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pfx(n,0);
        pfx[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pfx[i]=pfx[i-1]+(long long)nums[i];
        }
        unordered_map<int,int>mp;
        int l=0,r=0;
        long long ans=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp[nums[r]]>1 || mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            if(mp.size()==k){
                ans = max(ans,pfx[r]-pfx[l]+nums[l]);
            }
            r++;
        }
                return ans;
    }
};