class Solution {
public:
    int solve(vector<int> &nums,int k){
        int ans=0,j=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1)
            count++;
            while(count>k && j<=i){
                if(nums[j]&1) count--;
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};