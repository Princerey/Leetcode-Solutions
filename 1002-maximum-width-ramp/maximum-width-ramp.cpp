class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n);
        right[n-1] = nums[n-1];

        for(int i = n-2; i>=0; i--){
            right[i] = max(right[i+1], nums[i]);
        }

        int i = 0, j = 0, ans = 0;
        while(j<n){
            while(i<j && nums[i]>right[j]){
                i++;
            }
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};