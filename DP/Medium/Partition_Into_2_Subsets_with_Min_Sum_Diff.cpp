class Solution {
public:
    vector<int>v;
    void isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<bool>>mat(arr.size()+1,vector<bool>(sum+1,false));
        int n=arr.size();
        mat[0][0]=true;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<sum+1;j++)
        //     {
        //         if(i==0) mat[i][j]=false;
        //         if(j==0) mat[i][j]=true;
        //     }
        // }
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    if((mat[i-1][j-arr[i-1]]==true)||(mat[i-1][j]==true))mat[i][j]=true;
                }
                else mat[i][j]=mat[i-1][j];
            }
        }
        for(int i=0;i<=(sum)/2;i++)
        {
            if(mat[n][i]==true)v.push_back(i);
        }
        return ;
    }
    int minDifference(vector<int>& arr) {
        int range=0,mn=INT_MAX;
        v.clear();
        for(int i:arr) range+=i;
        // vector<vector<bool>>mat(nums.size(),vector<bool>(sum,vector<bool>(nums.size(),false)));
        isSubsetSum(arr,range);
        for(int i=0;i<v.size();i++)
        {
            mn=min(mn,range-2*v[i]);
        }
        return mn;
    }
};
