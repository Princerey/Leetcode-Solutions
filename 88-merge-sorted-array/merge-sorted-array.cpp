#include <vector>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> A(m + n);
        for(int i = 0; i < m; ++i) {
            A[i] = nums1[i];
        }
        for(int i = 0; i < n; ++i) {
            A[m + i] = nums2[i];
        }
        std::sort(A.begin(), A.end());
        
        for(int i = 0; i < m + n; ++i) {
            nums1[i] = A[i];
        }
    }
};
