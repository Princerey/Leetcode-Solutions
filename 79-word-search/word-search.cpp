vector<int> xm{-1, +1, 0, 0};
vector<int> ym{0, 0, -1, +1};

bool find(int pos, int x, int y, string word, vector<vector<char>> &g, vector<vector<int>> &vis)
{   
    if(vis[x][y] == 1)
        return false;

    vis[x][y] = 1;

    if(pos == word.size())
        return true;

    for(int i=0; i<4; ++i)
    {
        int xn = x + xm[i];
        int yn = y + ym[i];

        if(xn>=0 && xn!=g.size() && yn>=0 && yn!=g[0].size() && g[xn][yn] == word[pos])
        {
            bool stat = find(pos+1, xn, yn, word, g, vis);

            if(stat)
                return true;
        }
    }

    vis[x][y] = 0;
    return false;
}


class Solution {
public:
    bool exist(vector<vector<char>>& g, string word) {

        vector<int> temp(g[0].size(), 0);
        vector<vector<int>> vis(g.size(), temp);

        for(int i=0; i<g.size(); ++i)
        {
            for(int j=0; j<g[0].size(); ++j)
            {
                if(g[i][j] == word[0])
                {
                    if( find(1, i, j, word, g, vis) )
                        return true;
                }
            }
        }

        return false;
    }
};