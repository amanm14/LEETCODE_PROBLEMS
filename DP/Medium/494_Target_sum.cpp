class Solution {
public://n*total(sumatin of arrr) is tc and sc
    // vector<int>v;
    void isSubsetSum(vector<int>&arr,int sum,vector<vector<int>>&mat)
    {

        //             dp[i][j]
        //                |
        //       ┌────────┴────────┐
        //       ↓                 ↓
        //  Don't take          Take
        //  dp[i-1][j]       dp[i-1][j-num]
        //       └────────┬────────┘
        //                ↓
        //               SUM
      
        mat[0][0]=true;
        for(int i=1;i<arr.size()+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                // DON'T take arr[i-1]
                mat[i][j] = mat[i-1][j];

                // TAKE arr[i-1]
                if(arr[i-1] <= j)
                {
                    mat[i][j] += mat[i-1][j-arr[i-1]];
                }
            }
        }
        // for(int i=0;i<sum+1;i++)
        // {
        //     if(mat[arr.size()][i]==true) v.push_back(i);
        //     // cout<<"hello "<<endl;
        // }
        return ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int range=0,mn=INT_MAX;
        // v.clear();
        int cnt=0;

        for(int i:nums) range+=i;

        if(abs(target) > range)
            return 0;

        if((range + target) % 2 != 0)
            return 0;

        int sum = (range + target) / 2;
        vector<vector<int>>mat(nums.size()+1,vector<int>(sum+1,false));
        isSubsetSum(nums,sum,mat);
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i]<<" ";
        //     if(range-v[i]==target)
        //     {
        //         cnt++;
        //     }
        // }
        return mat[nums.size()][sum];
    }
};
// class Solution {
// public:
//     void isSubsetSum(vector<int>& arr, int sum) {
//         // code here
        
//         // for(int i=0;i<n;i++)
//         // {
//         //     for(int j=0;j<sum+1;j++)
//         //     {
//         //         if(i==0) mat[i][j]=false;
//         //         if(j==0) mat[i][j]=true;
//         //     }
//         // }
//         vector<vector<bool>>mat(arr.size()+1,vector<bool>(sum+1,false));
//         int n=arr.size();
//         mat[0][0]=true;
//         for(int i=1;i<n+1;i++)
//         {
//             for(int j=0;j<sum+1;j++)
//             {
//                 if(arr[i-1]<=j)
//                 {
//                     if((mat[i-1][j-arr[i-1]]==true)||(mat[i-1][j]==true))mat[i][j]=true;
//                 }
//                 else mat[i][j]=mat[i-1][j];
//             }
//         }
//         for(int i=0;i<=(sum)/2;i++)
//         {
//             if(mat[n][i]==true)v.push_back(i);
//         }
//         return ;
//     }
//     int minDifference(vector<int>& arr) {
//         int range=0,mn=INT_MAX;
//         v.clear();
//         for(int i:arr) range+=i;
//         // vector<vector<bool>>mat(nums.size(),vector<bool>(sum,vector<bool>(nums.size(),false)));
//         isSubsetSum(arr,range);
//         for(int i=0;i<v.size();i++)
//         {
//             mn=min(mn,range-2*v[i]);
//         }
//         return mn;
//     }
// };
