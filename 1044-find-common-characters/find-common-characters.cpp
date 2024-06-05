class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int arr[26];
        for(int i=0; i<26; i++)arr[i] = INT_MAX;
        for(string s:words){
            int currArr[26]{0};
            for(char c:s){
                currArr[c-'a']++; 
            }
            for(int i=0; i<26; i++){
                arr[i] = min(arr[i],currArr[i]);
            }
        }
        for(int i=0; i<26; i++){
            for(int j=0; j<arr[i]; j++){
                char c = static_cast<char>('a'+i);
                string s = "";
                s += c;
                res.push_back(s);
            }
        }
        return res;
    }
};