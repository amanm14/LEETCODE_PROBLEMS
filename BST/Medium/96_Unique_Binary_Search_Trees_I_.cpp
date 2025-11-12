class Solution {
public:
    // long long fact(long long x){
    //     if(x==1) return 1;
    //     return x*fact(x-1);
    // }
    // long long solve(int x,int y){
        
    //         long long z=fact(x);
    //         long long z1=fact(y)*fact(x-y);
    //         return z/z1;
        
    // }
    int numTrees(int n) {
        // return (solve(2*n,n)/(n+1)); //int overflow4

        // we are using dp solution 
        
        vector<int>dp(n+1,0);
        dp[0]=dp[1]=1;

        for(int i=2;i<=n;++i){
            for(int j=1;j<=i;++j){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};
