class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pref_xor((int)arr.size()+1);
        int _xor=0;
        pref_xor[0]=0;
        for(int i=0;i<(int)arr.size();i++){
            _xor^=arr[i];
            pref_xor[i+1]=_xor;
        }
        vector<int> res;
        for(auto x:queries){
            int L=x[0],R=x[1];
            res.push_back(pref_xor[R+1]^pref_xor[L]);
        }
        return res;
    }
};