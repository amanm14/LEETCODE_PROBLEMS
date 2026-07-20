class Solution {
public://O(n*m) is tc and sc is O(n)
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>ans(matrix.size());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                ans[i]+=matrix[i][j];
            }
        }
        return ans;
    }
};
