class Solution {
public:
  vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for(auto &e: edges) g[e[0]].push_back(e[1]),g[e[1]].push_back(e[0]);

    for(int i = 0; i != n; i++)
      if(g[i].size() == 1){
        vector<vector<int>> ans(n, vector<int>(1));
        vector<int> vis(n,0);
        queue<int> q;
        q.push(i);
        int id = -1;
        while(!q.empty()){
          int x = q.front(); q.pop();
          if(vis[x]) continue;
          vis[x] = 1;
          ans[++id][0] = x; 

          for(int next: g[x])
            if(vis[next] == 0) q.push(next);
        }
        return ans;
      }    

    for(int i = 0; i != n; i++)
      if(g[i].size() == 2){
        vector<pair<int,int>> t1;
        vector<int> vis(n,-1);
        queue<int> q;
        q.push(i);  
        for(int wave = 0; !q.empty() && t1.size() != 4; wave++)
          for(int n = q.size(); n; n--){
            int x = q.front(); q.pop();
            if(vis[x] != -1) continue;
            vis[x] = wave;
            if(g[x].size() == 2) t1.push_back({x, wave});

            for(int next: g[x])
              if(vis[next] == -1) q.push(next);
          }
        
        int Y = t1[1].second - t1[0].second + 1; 
        int X = t1[2].second - t1[0].second + 1; 
        vector<vector<int>> ans(Y, vector<int>(X, -1));
        
        queue<tuple<int, int, int>> Q;
        Q.push({t1[1].first, Y-1, 0});
        while(!Q.empty()){
          auto [x,r,c] = Q.front(); Q.pop(); 
          if(r == -1 || c == X || ans[r][c] != -1) continue;
          ans[r][c] = x;

          for(int next: g[x])
            if(vis[next] != -1)
              if(vis[next] < vis[x]) Q.push({next, r-1, c});
              else                   Q.push({next, r, c+1});

          vis[x] = -1;
        }

        return ans;
      }  

    return g;
  }
};