class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int time = n / 2;
        for (int i = 0; i < time; i++) {
            char temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp;
        }
    }
};
