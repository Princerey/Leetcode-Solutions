class Solution {
public:
    bool isPossible(string str1, string str2){
        int n = str1.length();
        int diff=0;
        for (int i=0;i<n;i++){
            if (str1[i] != str2[i]) diff++;
            if (diff > 1) return false;
        }
         return true;
    }


     void dfs(string str, vector<pair<string, int>> &levels, vector<vector<string>> &ans,
            vector<string> &vec, vector<pair<string,int>>::reverse_iterator it,int count,string &beginWord)
            {
                 if (str == beginWord){
                    vec.push_back(str);
                    reverse(vec.begin(), vec.end());
                    ans.push_back(vec);
                    reverse(vec.begin(), vec.end());
                    vec.pop_back();
                    return ;
                 }

                 while (it!=levels.rend() && it->second==count) it++;
                 while (it!=levels.rend() && it->second==count-1) {
                    if (isPossible(str, it->first)){
                        vec.push_back(str);
                        dfs(it->first, levels, ans, vec, it, count-1, beginWord);
                        vec.pop_back();
                    }
                    it++;
                 }
            }
  
     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       int n = wordList.size();
       unordered_set<string> dict;
       for (auto &x: wordList){
        if (x != beginWord) dict.insert(x);
       }

       queue<string> q;
       q.push(beginWord);
       vector<pair<string, int>> levels;
       int count = 0;
       bool flag = false;

       while(!q.empty()){
          int size = q.size();
          while (size--){
              string node = q.front();
              q.pop();

              levels.push_back({node, count});
              if (node == endWord){
                flag = true;
                break;
              }

              for (int i=0;i<node.length();i++){
                char original = node[i];
                for (char ch='a';ch<='z';ch++){
                     if (original == ch) continue;
                     node[i] = ch;

                     if (dict.find(node) != dict.end()){
                        q.push(node);
                        dict.erase(node);
                     }
                }
                node[i] = original;
              }
          }
          if (flag) break;
          count++;
       }
       
        vector<pair<string,int>>::reverse_iterator it=levels.rbegin();
        vector<vector<string>> ans;
        vector<string> vec;
        if (!flag) return ans;

        dfs(endWord, levels, ans, vec, it, count, beginWord);
        return ans;
    }
};