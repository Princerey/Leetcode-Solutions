class Solution {
private:
    int helper(int number){
        int ans = 0;
        while(number){
            ans += (number % 10);
            number /= 10;
        }
        return ans;
    }
public:
    int getLucky(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        k--;
        int sumVal = 0;
        for(auto &ch : s){
            sumVal += helper((ch - 'a') + 1);
        }
        while(k > 0){
            sumVal = helper(sumVal);
            k--;
        }
        return sumVal;
    }
};