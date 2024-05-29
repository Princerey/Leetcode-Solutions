class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int c =1;
        int element = nums[0];
        for(int i=1; i<nums.size(); i++) 
        {
            if(nums[i]== element) 
                c++;             
            else                  
            {
                c--;               
                if(c==0)
                    element = nums[i+1];
            }
        }
        return element;
    }
};