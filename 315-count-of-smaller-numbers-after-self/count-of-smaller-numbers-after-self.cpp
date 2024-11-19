#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        reverse(nums.begin(), nums.end());
        vector<int>ans;
        pbds<int>pbds;
        for(auto val:nums)
        {
            pbds.insert(val);
            int cnt = pbds.order_of_key(val);
            ans.push_back(cnt);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};