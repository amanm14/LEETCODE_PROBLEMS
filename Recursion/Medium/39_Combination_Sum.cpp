class Solution {
public:
// Time Complexity:  t is taret and m is smallest value in candidates
// O(2T/m)

//  (worst-case exponential)
// Auxiliary Space:  O(T/m)
// 	​

// Total Space (including output): O(T/m+K×L)
// 	​

    void dfs(int idx,int t,vector<vector<int>>&ans,vector<int>&temp,int n,vector<int>&c)
    {
        if(t==0){
            ans.push_back(temp);

            return ;
        }
        if(idx==n) return ;
        if(t<0) return ;
        temp.push_back(c[idx]);
        dfs(idx,t-c[idx],ans,temp,n,c);
        temp.pop_back();
        dfs(idx+1,t,ans,temp,n,c);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        // for(int i=0;i<candidates.size();i++)
        // {
            dfs(0,target,ans,temp,candidates.size(),candidates);
        // }
        return ans;
    }
};
