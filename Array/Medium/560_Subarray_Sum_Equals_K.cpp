class Solution {
public:
    // void rec(vector<int>&nums,int k,int&ans,int i)
    // {
    //     if(currk==0){
    //         ans++;
    //         return;
    //     }
    //         if(currk-nums[i]>=0)
    //         {
    //             rec(nums,k,currk-nums[i],ans,i+1);
    //             return ;
    //         }
    //         else{
    //             rec(nums,k,k,ans,i+1);
    //             return;
    //         }
    // }
    int subarraySum(vector<int>& nums, int k) {
        int ans=0,res=0,initial=0;//O(N) is tc and
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            res+=nums[i];
            // mp[res]=i;
            if(mp.find(res-k)!=mp.end()){
                ans+=mp[res-k];
            }
            mp[res]++;
        }
        // rec(nums,k,k,ans,0);
        return ans;
    }
};
