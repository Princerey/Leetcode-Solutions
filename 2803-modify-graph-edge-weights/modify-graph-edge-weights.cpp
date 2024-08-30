class Solution {
public:
    
    long long D[107][107];
    void floyd(int n){
       for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]); 
                }
            }
        }
    }
    
    void recalc(int a,int b,int x,int n){
        for(int i  = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                D[i][j] = min({D[i][j],D[i][a]+x+D[b][j],D[i][b]+x+D[a][j]});
            }
        }
    }
    
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int s, int d, int t) {
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j)D[i][j]= 0;
                else D[i][j] = 1e12;
            }
        }
        int id = 0;
        vector<int> test;
        for(auto c:edges){
            int u = c[0];
            int v = c[1];
            int w = c[2];
            if(w != -1){
                D[v][u] = w;   
                D[u][v] = w;
            }
            else
                test.push_back(id);
            id++;
        }
            
        floyd(n);
        if(D[s][d]<t)return {};
        
        
        for(int i = 0;i<test.size();i++){
            if(D[s][d]==t){
                edges[test[i]][2] = 2e9;
                continue;
            }
            int u = edges[test[i]][0];
            int v = edges[test[i]][1];
        
            long long nwMin1 = D[s][u]+1+D[v][d];
            long long nwMin2 = D[s][v]+1+D[u][d];
            
            long long mn = min(nwMin1,nwMin2);
            if(mn>t){
                recalc(u,v,1,n);
                edges[test[i]][2] = 1;
            }
            else{
                recalc(u,v,1+(t-mn),n);
                edges[test[i]][2] = 1+(t-mn);
            }
        }
        cout<<D[s][d]<<endl;
        if(D[s][d]!=t)return {};
        return edges;
    }
};