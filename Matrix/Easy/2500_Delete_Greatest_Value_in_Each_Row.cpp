class Solution {
public://O(mn logn) is tc and sc is O(1) we can use frequency as elemenrt is 1 to 100 to avoid extra logn
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<grid.size();i++)
        {

            sort(grid[i].begin(),grid[i].end());
            
        }
        while(n>0)
        {
            int ma=0;
            for(int i=0;i<m;i++)
            {
                ma=max(ma,grid[i][n-1]);
                grid[i].pop_back();
            }
            n--;
            ans+=ma;
        }
        return ans;
    }
};
