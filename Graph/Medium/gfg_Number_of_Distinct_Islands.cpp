// User function Template for C++

class Solution {
  public://O(n*m) is tc and sc with extr set and vector storage
    vector<pair<int,int>> bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        vis[i][j]=1;
        
        vector<pair<int,int>>st;
        st.push_back({0,0});
        q.push({i,j});
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            
            int delr[]={-1,0,1,0};
            int delc[]={0,1,0,-1};
            for(int k=0;k<4;k++)
            {
                int nr=r+delr[k];
                int nc=c+delc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&
                !vis[nr][nc]&&grid[nr][nc]==1){
                    
                        vis[nr][nc]=1;
                        st.push_back({nr-i,nc-j});
                        q.push({nr,nc});
                        
                }
            }
        }
        return st;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&& !vis[i][j]){
                    st.insert(bfs(i,j,vis,grid));
                    
                }
            }
        }
        return st.size();
    }
};
