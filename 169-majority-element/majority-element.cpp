class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int k = (n/2);
        for(i=0;i<n;i++)
        {
            int count =0;
            for(int j=0;j<n;j++)
            {
                if(nums[i] == nums[j])
                count++;
            }
            if(count > k )
            {
            break;
            }
        }
        return nums[i];
        
    }
};