class Solution {
public://O(n*m) is tc and sc
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }

        
        int tm=0;
        while(!q.empty())
        {
            int row=q.front().first.first;
            
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            // if(vis[row][col]!=2&&grid[row][col]==1)vis[row][col]=2;
            for(int delr=-1;delr<=1;delr++)
            {
                for(int delc=-1;delc<=1;delc++){
                    int nr=row+delr;
                    int nc=col+delc;

                    if((delr==0||delc==0)&&nr>=0&&nr<n&&nc>=0&&nc<m&&
                    vis[nr][nc]!=2&&grid[nr][nc]==1){
                        q.push({{nr,nc},t+1});
                        vis[nr][nc]=2;
                        // vis[nr][nc]=1;
                        // tm=max(tm,t);
                    }

                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]!=2&&grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};
