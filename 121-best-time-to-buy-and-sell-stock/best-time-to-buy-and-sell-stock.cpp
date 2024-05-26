class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int mini = prices[0];
    int maxP = 0;
    int n = prices.size();
    for(int i = 1;i<n;i++)
    {
        int profit = prices[i] - mini;
        maxP = max(maxP,profit);
        mini = min (mini , prices[i]);
    }
    return maxP;
    }
};