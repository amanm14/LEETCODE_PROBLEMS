class Solution {
public://tc is O(n^2)+O(n^2) for queue and For SC it is O(n*m)*8(neighbours checking)
    void bfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&grid)
    {
        vis[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            //traversal in neighbours to chec k and mark vis
            for(int delr=-1;delr<=1;delr++)
            {
                for(int delc=-1;delc<=1;delc++)
                {
                    int nrow=row+delr;
                    int ncol=col+delc; // we are using the (delr==0||delc==0) because we only have to check in 4 directionnot in diagonal direction here in leetcode question 
                    if((delr==0||delc==0)&&nrow>=0&& nrow<n &&ncol>=0 && ncol <m &&
                        grid[nrow][ncol]=='1'&& !vis[nrow][ncol])
                    {
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size(),cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='1')
                {
                    cnt++;
                    bfs(i,j,vis,grid);
                    
                }
            }
        }
        return cnt;
    }
};
