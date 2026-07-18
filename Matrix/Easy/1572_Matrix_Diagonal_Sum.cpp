class Solution {
public://O(n*m) is tc and  sc is o(1)
    int diagonalSum(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();)
        {

            for(int j=0;j<mat[0].size();)
            {
                cout<<mat[i][j];
                ans+=mat[i++][j++];
            }
        }
        for(int i=mat.size()-1;i>=0;)
        {

            for(int j=0;j<mat[0].size();)
            {
                if(i!=j) ans+=mat[i--][j++];
                else{
                    i--;
                    j++;
                }
            }
        }
        return ans;
    }
};
