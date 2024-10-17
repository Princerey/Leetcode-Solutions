class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        vector<int> factorial(n, 1);
        string result = "";
        
        
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        
        
        for (int i = 1; i < n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        
        
        --k;
        
        for (int i = 0; i < n; ++i) {
            int index = k / factorial[n - 1 - i];
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= factorial[n - 1 - i];
        }
        
        return result;
    }
};