class Solution {
public://O(n^2) is tc and sc is O(n)
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int l=0;
        vector<int>ans;
        for(int i=0;i<matrix.size();i++)
        {
            int mi=INT_MAX;
            int ma=INT_MIN,temp;
            for(int j=0;j<matrix[i].size();j++)
            {
                if(mi>matrix[i][j]){
                    temp=j;
                    mi=matrix[i][j];
                }
            }
            for(int i1=0;i1<matrix.size();i1++)
            {
                ma=max(matrix[i1][temp],ma);
            }
            // cout<<ma<<"  "<<mi<<endl;
            if(ma==mi) ans.push_back(mi);
        }
        return ans;
    }
};
