class Solution {
public://O(n*2^n) is tc and O(n+K⋅n) is sc where K is the number of valid combinations
     void dfs(int idx,int t,vector<vector<int>>&ans,vector<int>&temp,int n,vector<int>&c)
    {
        if(t==0){
            ans.push_back(temp);

            return ;
        }
        if(idx>=n) return ;
        if(t<0) return ;
        

for (int i = idx; i < n; i++) {
    if (i > idx && c[i] == c[i - 1]) continue;

    temp.push_back(c[i]);
    dfs(i + 1,t-c[i],ans,temp,n,c);
    temp.pop_back();
}
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        vector<int>temp;
        // for(int i=0;i<candidates.size();i++)
        // {
            dfs(0,target,ans,temp,candidates.size(),candidates);
        // }
        return ans;
    }
};
