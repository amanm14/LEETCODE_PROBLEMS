class Solution {
public://O(N^2) is tc and O(n) is sc
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        for(int i=0;i<mat.size();i++)
        {
            int cnt=0;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==1) cnt++;
            }
            ans.push_back({cnt,i});
        }
        sort(ans.begin(),ans.end());
        vector<int>a;
        int nc=0;
        for(auto i:ans)
        {
            a.push_back(i.second);
            if(k-1==nc) return a;
            nc++;
        }
        return a;
    }
};
