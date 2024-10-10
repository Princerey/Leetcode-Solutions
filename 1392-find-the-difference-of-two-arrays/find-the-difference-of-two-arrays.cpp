class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n = size(nums1), m = size(nums2);
        set<int> s1(begin(nums1),end(nums1)),s2(begin(nums2),end(nums2)),common;
        vector<vector<int>> ans(2);
        set_intersection(begin(s1),end(s1),begin(s2),end(s2),inserter(common,begin(common)));
        for(int i=0; i<2; ++i){
            if(i) swap(s1,s2);
            for(auto&x: s1)
                if(!common.count(x)) ans[i].push_back(x);
        }
        return ans;
    }
};