class Solution {
public://O(n*m) is tc and O(1) is sc
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]<0)
                {
                    ans+=(grid[i].size()-j);
                    break;
                    // cout<<i<<" "<<j<<" ";
                    // cout<<ans<<endl;
                }
            }
        }
        return ans;
    }
};
