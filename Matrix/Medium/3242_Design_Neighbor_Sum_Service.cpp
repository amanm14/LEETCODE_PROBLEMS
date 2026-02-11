class NeighborSum {
public://O(N2) is t and O(N2) is sc
    vector<vector<int>>z;
    NeighborSum(vector<vector<int>>& grid) {
        z=grid;
    }
    
    int adjacentSum(int value) {
        int ii=0;
        int jj=0;
        for(int i=0;i<z.size();i++)
        {
            for(int j=0;j<z[0].size();j++)
            {
                if(z[i][j]==value){
                    ii=i;
                    jj=j;
                    break;
                }
            }
        }
        int ans=0;
        if(ii-1>=0){
            ans+=z[ii-1][jj];
        }
        if(jj-1>=0){
            ans+=z[ii][jj-1];
        }
        if(ii+1<z.size()){
            ans+=z[ii+1][jj];
        }
        if(jj+1<z[0].size()){
            ans+=z[ii][jj+1];
        }
        return ans;
    }
    
    int diagonalSum(int value) {
        int ii=0;
        int jj=0;
        for(int i=0;i<z.size();i++)
        {
            for(int j=0;j<z[0].size();j++)
            {
                if(z[i][j]==value){
                    ii=i;
                    jj=j;
                    break;
                }
            }
        }
        int ans=0;
        if(ii-1>=0&&jj-1>=0){
            ans+=z[ii-1][jj-1];
        }
        if(ii+1<z.size()&&jj+1<z[0].size()){
            ans+=z[ii+1][jj+1];
        }
        if(ii-1>=0&&jj+1<z[0].size()){
            ans+=z[ii-1][jj+1];
        }
        if(ii+1<z.size()&&jj-1>=0){
            ans+=z[ii+1][jj-1];
        }
        return ans;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
