// class Solution { //recursion backtracking with pruning -->TLE 45/65
// public://Time Complexity=O(k^n+1) and sc is O(n+k)​
//     void dfs(vector<int>& jobs, int idx, int k,int&ans,vector<int>&worker,int t)
//     {
//         if(idx==jobs.size()){
//             // ans=min(ans,maxWt);
            
//             ans=min(ans,t);
//             return;
//         }

//         // if(ans<INT_MAX&&maxWt>ans) return ans;
//         // idx++;

//         // int tempAns=0;
//         // for(int i=0;i<worker.size();i++)
//         // {
            
//         // }
//         if(t>=ans){
//             return;
//         }


//         for(int i=0;i<k;i++)
//         {
//             worker[i]+=jobs[idx];
//              int newMax=max(t,worker[i]);
//             dfs(jobs,idx+1,k,ans,worker,newMax);
//              worker[i]-=jobs[idx];
//         }
//         // ans=min(tempAns,ans);
//         return ;
//     }
//     int minimumTimeRequired(vector<int>& jobs, int k) {
//         vector<int>worker(k);
//         int ans=INT_MAX;
//         sort(jobs.begin(),jobs.end());
//         // reverse(jobs.begin(),jobs.end());
//         dfs(jobs,0,k,ans,worker,0);
//         return ans;
//     }
// };
class Solution {
public:// bit masking --> DP O(k.3^n) is tc and sc is (k.2^n) 
    int minimumTimeRequired(vector<int>& jobs, int k) {
        const int n = jobs.size();
        
        vector<int> sums(1<<n);
        for (int b = 0; b < (1<<n); ++b) {
            for (int i = 0; i < n; ++i) {
                if ((1<<i) & b) sums[b] += jobs[i]; 
            }    
        }
        
        vector<vector<int>> dp(k+1, vector<int>(1<<n));
        for (int b = 0; b < (1<<n); ++b) dp[1][b] = sums[b];
        for (int i = 2; i <= k; ++i) {
            for (int b = 1; b < (1<<n); ++b) {
                dp[i][b] = dp[i-1][b];
                for (int tb = b; tb; tb = (tb-1)&b) {
                    dp[i][b] = min(dp[i][b], max(sums[tb], dp[i-1][b-tb]));
                }
            }
        }
        return dp[k][(1<<n)-1];
    }
};
