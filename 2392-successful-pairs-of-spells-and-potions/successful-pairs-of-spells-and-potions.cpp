class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m=potions.size(), n=spells.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            int left=0, right=m-1;
            while(left<=right){
                int mid=(left+right)/2;
                long long temp = (long long)potions[mid]*spells[i];
                if(temp<success)
                  left=mid+1;
                else right=mid-1;
            }
            ans.push_back(m-left);
        }
        return ans;
    }
};