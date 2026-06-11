class Solution {
public://O(n*m) is tc and sc
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){//if you are giving variable of column then loop would also be of columns
            if(grid[0][i]==1){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(grid[n-1][i]==1){//we use just opposite if we are looping column(m) here we will use row (n)
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int delr[]={0,1,0,-1};
            int delc[]={1,0,-1,0};
            for(int k=0;k<4;k++)
            {
                int nr=i+delr[k];
                int nc=j+delc[k];
                
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&
                grid[nr][nc]==1&&!vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }

            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};
