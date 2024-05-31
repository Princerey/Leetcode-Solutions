class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (i < n - 1) {
                if (s[i] == 'I' && s[i + 1] == 'V') {
                    sum += 4;
                    i++;
                    continue;
                }
                if (s[i] == 'I' && s[i + 1] == 'X') {
                    sum += 9;
                    i++;
                    continue;
                }
                if (s[i] == 'X' && s[i + 1] == 'L') {
                    sum += 40;
                    i++;
                    continue;
                }
                if (s[i] == 'X' && s[i + 1] == 'C') {
                    sum += 90;
                    i++;
                    continue;
                }
                if (s[i] == 'C' && s[i + 1] == 'D') {
                    sum += 400;
                    i++;
                    continue;
                }
                if (s[i] == 'C' && s[i + 1] == 'M') {
                    sum += 900;
                    i++;
                    continue;
                }
            }
            
            if (s[i] == 'I') sum += 1;
            else if (s[i] == 'V') sum += 5;
            else if (s[i] == 'X') sum += 10;
            else if (s[i] == 'L') sum += 50;
            else if (s[i] == 'C') sum += 100;
            else if (s[i] == 'D') sum += 500;
            else if (s[i] == 'M') sum += 1000;
        }
        
        return sum;
    }
};
