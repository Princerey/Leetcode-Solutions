class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(points.begin(),points.end());
        int x=points[0][1];
        int cnt=1;
        for(int i=1;i < points.size();i++){
          if(x<points[i][0] ){
            cnt++;
            x=points[i][1];
          }
          x=min(x,points[i][1]);
        }
        return cnt;
    }
};