class Solution {
    void simple_tokenizer(string s, vector<string>& v)
    {
        stringstream ss(s);
        string word;
        while (ss >> word) {
            v.push_back(word);
        }
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1;
        simple_tokenizer(sentence1,s1);
        vector<string> s2;
        simple_tokenizer(sentence2,s2);

        int i=0,j=s1.size()-1;
        int a=0,b=s2.size()-1;
        while(a<b+1 && i<j+1 && s1[i]==s2[a]){
            i++; a++;
        }
        while(b>=a && j>=i && s1[j]==s2[b]){
            j--; b--;
        }
        if(i>j || a>b)
            return true;
        return false;
    }
};