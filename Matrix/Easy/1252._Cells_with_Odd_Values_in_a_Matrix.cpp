class Solution {
public://O(m*n) is tc and sc we can optimize the space by creating 1d arrray se[arate for row and col that will make the sc to O(m+n)
    int oddCells(int m, int n, vector<vector<int>>& indices) 
    {
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<indices.size();i++)
        {
            int x=indices[i][0];
            for(int j=0;j<n;j++)
            {
                int t=ans[x][j];
                t++;
                ans[x][j]=t;
            }
            int y=indices[i][1];
            for(int j=0;j<m;j++)
            {
                int t=ans[j][y];
                t++;
                ans[j][y]=t;
            }
        }
        int a=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]%2!=0) a++;
            }
        }
        return a;
    }
};
