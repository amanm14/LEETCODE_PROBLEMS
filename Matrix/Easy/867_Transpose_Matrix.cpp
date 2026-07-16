class Solution {
public://O(n*m) is tc and sc is O(m*n)
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j]=matrix[j][i];
            }
        }
        return ans;
    }
};
