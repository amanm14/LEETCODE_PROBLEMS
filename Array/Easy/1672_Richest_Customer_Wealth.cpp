class Solution {
public://O(m*n) is tc and O(1) is sc
    int maximumWealth(vector<vector<int>>& accounts) {
        int row=accounts.size();
        int col=accounts[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<row;i++){
            int ans=0;
            for(int j=0;j<col;j++){
              ans+=accounts[i][j];
            }
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};
