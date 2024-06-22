class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        int res = 0;
        umap[0]++;
        if(nums[0]%k<0){
            umap[nums[0]%k+k]++;
        }else{
            umap[nums[0]%k]++;
        }
        if(nums[0]%k == 0)++res;
        for(int i=1; i<nums.size(); i++){
            nums[i] = (nums[i-1]+nums[i])%k;
            if(nums[i]<0)nums[i]+= k;
            res += umap[nums[i]];
            umap[nums[i]]++;
        }
        return res;
    }
};