class Solution {
public:
    stack<int> st;
    int cycle = 0;
    void solve(int node,vector<int> adj[],vector<int> &vis,vector<int> &path_vis)
    {
        vis[node] = 1;
        path_vis[node] = 1;

        for(auto it:adj[node])
        {
            if(vis[it] && path_vis[it])
            cycle = 1;
            else if(!vis[it])
            solve(it,adj,vis,path_vis);
        }
        
        st.push(node);
        path_vis[node] = 0;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) 
    {
        vector<int> adj1[k + 1],adj2[k + 1];
        
        for(auto it:row)
        adj1[it[0]].push_back(it[1]);

        vector<int> vis(k + 1,0) , path_vis(k + 1,0);

        vector<int> v1,v2;

        for(int i=1;i<=k;i++)
        {
            if(!vis[i])
            solve(i,adj1,vis,path_vis);
        }

        if(cycle)
        return {};

        while(st.size() > 0)
        {
            v1.push_back(st.top());
            st.pop();
        }

        for(int i = 1;i<= k;i++)
        {
            vis[i] = 0;
            path_vis[i] = 0;
        }
        
        for(auto it:col)
        adj2[it[0]].push_back(it[1]);
        
        for(int i=1;i<=k;i++)
        {
            if(!vis[i])
            solve(i,adj2,vis,path_vis);
        }

        if(cycle)
        return {};

        while(st.size() > 0)
        {
            v2.push_back(st.top());
            st.pop();
        }

        vector<vector<int>> ans(k,vector<int>(k,0));

        unordered_map<int,int> mp1,mp2;

        for(int i=1;i<=k;i++)
        {
            mp1[v1[i-1]] = i;
            mp2[v2[i-1]] = i;
        }

        for(int i=1;i<=k;i++)
        ans[mp1[i]-1][mp2[i]-1] = i;

        return ans;

    }
};