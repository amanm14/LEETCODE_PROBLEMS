// class Solution { //TLE error to this solution b me need memoization
// public:
//     void dfs(int idx,vector<int>& nums,bool&ans,int sum,int Total)
//     {
//         if(idx>=nums.size()) return;
//         int remSum=0;
//         if(ans) return;
//         if(Total==sum){
//             ans=true;
//             return ;
//         }
//         for(int i=idx;i<nums.size();i++)
//         {
//             sum+=nums[i];
//             int z=Total-nums[i];
//             dfs(i+1,nums,ans,sum,z);
//             sum-=nums[i];
//         }
//         return ;
//     }
//     bool canPartition(vector<int>& nums) {
//         // sort(nums.begin(),nums.end()); logic faile at {2,2,1,1}
//         // int x=0;
//         // for(int i=nums.size()-1;i>=0;)
//         // {
            
//         //     x+=nums[i--];
//         //     int j=i;
//         //     int s2=0;
//         //     while(j>=0)
//         //     {
//         //         s2+=nums[j--];
//         //         cout<<" j and s2 "<<j<<" "<<s2<<"x "<<x<<endl;
//         //         if(s2>=x&&j>0)
//         //         {
//         //             break;
//         //         }
//         //         if(s2==x&&j<0)
//         //         {
//         //             return true;
//         //         }
//         //     }
//         // }
//         // return false;
//         int idx=0;
//         bool ans=false;
//         int Total=0;
//         for(auto it:nums){
//             Total+=it;
//         }
//         dfs(idx,nums,ans,0,Total);
//         return ans;
//     }
// };

class Solution {
public:
    int target;
    vector<vector<int>> dp;

    bool dfs(int idx,int sum,vector<int>&nums,int target)
{
    if(sum == target)
        return true;

    if(idx == nums.size())
        return false;

    if(sum > target)
        return false;

    if(dp[idx][sum] != -1)
        return dp[idx][sum];

    bool take = dfs(idx + 1, sum + nums[idx],nums,target);

    bool skip = dfs(idx + 1, sum,nums,target);

    return dp[idx][sum] = take || skip;
}

    bool canPartition(vector<int>& nums) {
       
    int total = 0;
    for (int x : nums)
        total += x;

    if (total % 2)
        return false;

    int target = total / 2;

    dp.resize(nums.size(), vector<int>(target + 1, -1));

    return dfs(0,0, nums, target);
    }
};

// | Approach                  | Time Complexity                                           | Space Complexity                                             |
// | ------------------------- | --------------------------------------------------------- | ------------------------------------------------------------ |
// | Your recursive solution   | **O(2ⁿ)** (often written as O(n·2ⁿ) due to loop overhead) | **O(n)**                                                     |
// | Memoization (Top-Down DP) | **O(n × target)**                                         | **O(n × target)**                                            |
// | Bottom-Up DP              | **O(n × target)**                                         | **O(n × target)** (or **O(target)** with space optimization) |
