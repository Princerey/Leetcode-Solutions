class Solution {
public:
    int mm;
    int nn;
    int t[201][201];
    vector<vector<int>> nums;
    int fun(int i,int j){
        if (i == mm-1 && j == nn-1) return nums[i][j];
        if (i>=mm || j>= nn) return INT_MAX;
        if (t[i][j] !=-1) return t[i][j];
        long right = fun(i,j+1);
        long down = fun(i+1,j);
        return t[i][j] =nums[i][j] + min(right,down);
    }
    int minPathSum(vector<vector<int>>& arr) {
        mm = arr.size();
        nn =arr[0].size();
        nums =arr;
        memset(t,-1,sizeof(t));
        return fun(0,0);
    }
};