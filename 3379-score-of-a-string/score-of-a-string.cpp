class Solution {
public:
    int scoreOfString(string s) {
        int n = s.length();
        int sum=0;
        for(int i=1;i<n;i++)
        {
        sum+=abs(int(s[i]) - int(s[i-1]));
        }
        return sum;
    }
};