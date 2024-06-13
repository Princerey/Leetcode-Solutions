class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        int size = s[0].size();
        string ans = "";

        for(int i=0;i<size;i++)
        {
            char ch = s[0][i];
            bool match = true;
            for(int j=1;j<n;j++)
            {
                if(s[j].size() < i || ch != s[j][i])
                {
                    match = false;
                    break;
                }
            }
            if(match == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
};