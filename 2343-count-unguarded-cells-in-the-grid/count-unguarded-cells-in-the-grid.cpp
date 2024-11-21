class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> safe(m, vector<bool>(n, true));
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int i = 0; i < guards.size(); i++){
            int x = guards[i][0];
            int y = guards[i][1];
            matrix[x][y] = 1;
        }
        for(int i = 0; i < walls.size(); i++){
            int x = walls[i][0];
            int y = walls[i][1];
            matrix[x][y] = 2;
        }             
        int safe_cnt = 0; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    int tempi = i, tempj = j+1;
                    while(tempj >= 0 && tempj < n){
                        if(matrix[tempi][tempj] == 2 || matrix[tempi][tempj] == 1)
                            break;
                        safe[tempi][tempj] = false;
                        tempj++;
                    }
                    cout<<endl;
                    tempi = i, tempj = j-1;
                    while(tempj >= 0 && tempj < n){
                        if(matrix[tempi][tempj] == 2 || matrix[tempi][tempj] == 1)
                            break;
                        safe[tempi][tempj] = false;
                        tempj--;
                    }
                    cout<<endl;
                    tempi = i+1, tempj = j;
                    while(tempi < m && tempi >= 0){
                        if(matrix[tempi][tempj] == 2 || matrix[tempi][tempj] == 1)
                            break;
                        safe[tempi][tempj] = false;
                        tempi++;
                    }
                    cout<<endl;
                    tempi = i-1, tempj = j;
                    while(tempi < m && tempi >= 0){
                        if(matrix[tempi][tempj] == 2 || matrix[tempi][tempj] == 1)
                            break;
                        safe[tempi][tempj] = false;
                        tempi--;
                    }
                    cout<<endl;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(safe[i][j] == true)
                    safe_cnt++;
            }
        }
        return safe_cnt - guards.size() - walls.size();
    }
};