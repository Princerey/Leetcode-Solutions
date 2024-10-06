class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int allOne = 0;
        int allZero = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                allOne++;
            }
            if(nums[i] == 0) {
                allZero++;
            }
        }

        if(allOne == n) {
            return n-1;
        }
        if(allZero == n) {
            return 0;
        }
        vector<int> temp;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(nums[i] == 0) {
                temp.push_back(sum);
                sum = 0;
            }
        }
        temp.push_back(sum);

        int ans = 0;
        int s = 0;
        for(int i = 0; i < 2; i++) {
            s += temp[i];
        }
        ans = max(ans, s);
        for(int i = 2; i < temp.size(); i++) {
            s += temp[i];
            s -= temp[i-2];
            ans = max(ans, s);
        }

        return ans;
        
    }
};