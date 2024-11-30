#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
auto _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();
class Solution {
    unordered_map<int,int> m;
    struct pa{int e,nxt;};
    vector<pa> lst;
    int lend;
    void fill(int st,vector<vector<int>> &adj,unordered_map<int,int> &ava){
        int e=st;
        while(1){
            lst[lend]=pa{e,lend+1};
            lend++;
            if(adj[e].empty()) return;
            int n=adj[e].back();
            adj[e].pop_back();
            if(adj[e].empty()) ava.erase(e);
            else ava[e]=lend-1;
            e=n;
        }
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        m.clear();
        int cnt=0;
        for(auto &v:pairs) for(int &e:v){
            const auto it=m.find(e);
            if(it==m.end()) {m.emplace_hint(m.end(),e,cnt); e=cnt++;}
            else e=it->second;
        }
        vector<int> rep(cnt,0),id2num;
        id2num.reserve(cnt);
        for(auto it=m.begin();it!=m.end();++it) id2num[it->second]=it->first;
        vector<vector<int>> adj(cnt);
        for(const auto &v:pairs) {adj[v[0]].emplace_back(v[1]);rep[v[0]]++,rep[v[1]]--;}
        int st=0;
        for(int i=0;i<cnt;++i) if(rep[i]==1) {st=i;break;}
        lend=0;
        unordered_map<int,int> ava;
        lst.resize(pairs.size()+1);
        fill(st,adj,ava);
        lst[lend-1].nxt=-1;
        while(!ava.empty()){
            int pre=ava.begin()->first,ind=ava.begin()->second;
            st=adj[pre].back();
            adj[pre].pop_back();
            if(adj[pre].empty()) ava.erase(ava.begin());
            int last=lst[ind].nxt;
            lst[ind].nxt=lend;
            fill(st,adj,ava);
            lst[lend-1].nxt=last;
        }
        int i=0;
        st=0;
        while(1){
            if(lst[i].nxt==-1) break;
            int n=lst[i].nxt;
            pairs[st][0]=id2num[lst[i].e];
            pairs[st][1]=id2num[lst[n].e];
            i=n;
            st++;
        }
        return pairs;
    }
};