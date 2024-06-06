class Solution {
public:
    int solve(vector<int> & nums,int index){
        if(index >= nums.size() - 1){
            return 0;
        }
        int a = nums[index],j = index+ 1;
        if(nums[index] + index >= nums.size()-1)
            return 1;
        int maxx = nums[index+1];
        
        for(int i=2;i<=a && i< nums.size();i++){
            if(maxx + j <= nums[index+i] + index + i){
                maxx = nums[index+i];
                j  = index + i;
            }
        }
        return 1 + solve(nums,j);
    }
    int jump(vector<int>& nums) {
        int steps = solve(nums, 0);
        return steps;
    }
};