class Solution {
public://O(n^2) is tc and sc
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        vector<vector<int>>ans1(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            int mov=rowShift[i];
            for(int j=0;j<n;j++)
            {
                // int temp=grid[i][(j - mov + n) % n];
                ans1[i][j]=grid[i][(j + mov) % n];
                // ans[i][j]=grid[i][(j - mov + n) % n];
                // grid[i][j]=temp;
            }
        }
        for(int i=0;i<n;i++)
        {
            int mov=colShift[i];
            for(int j=0;j<n;j++)
            {
                // int temp=grid[(j - mov + n) % n][i];
                ans[j][i]=ans1[(j + mov ) % n][i];
                // ans[j][i]=grid[(j - mov + n) % n][i];
                // grid[i][j]=temp;
            }
        }
        return ans;
    }
};
