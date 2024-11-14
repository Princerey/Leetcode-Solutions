class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *std::max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canDistribute(n, quantities, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }
        
        return result;
    }
    private:
    bool canDistribute(int n, const std::vector<int>& quantities, int maxProducts) {
        int requiredStores = 0;

        for (int quantity : quantities) {
            requiredStores += (quantity + maxProducts - 1) / maxProducts;
            if (requiredStores > n) return false;
        }

        return true;
    }
};