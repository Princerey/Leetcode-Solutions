class Solution {
public:
    void dfs(int node,int parent, bool&isCycle, unordered_map<int, vector<int>>&m, vector<int>&visited,vector<int>&dfs_visited,stack<int>&st){

        visited[node] = 1;
        dfs_visited[node] = 1;

        for(auto i : m[node]){
            if(visited[i] == 1 && dfs_visited[i] == 1){
                isCycle = true;
            }
            if(!visited[i]){
                dfs(i,node,isCycle,m,visited,dfs_visited,st);
            }
        }

        dfs_visited[node] = 0;
        st.push(node);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> answer;
        bool isCycle = false;

        if(prerequisites.size() == 0){
            for(int i=0;i<numCourses;i++){
                answer.push_back(i);
            }
            return answer;
        }

        unordered_map<int, vector<int>> m;
        for(auto i : prerequisites){
            int u = i[0];
            int v = i[1];

            m[v].push_back(u);
        }   

        vector<int> visited(numCourses,0);
        vector<int> dfs_visited(numCourses,0);
        stack<int> st;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                dfs(i,-1,isCycle,m,visited,dfs_visited,st);
            }
        }
        if(isCycle){
            return answer;
        }
        while(!st.empty()){
            int top = st.top();
            st.pop();
            answer.push_back(top);
        }
        return answer;
    }
};