class Solution {
public://O(n) is tc and O(1) sc
    int numSubarrayProductLessThanK(vector<int>& nums, int k){
        int j=0,ans=0;
        long long a=1;
        for(int i=0;i<nums.size();i++)
        {
            a=a*nums[i];
            
                while(a>=k&&j<=i){
                    a=a/nums[j++];
                }

                ans+=i-j+1;
            }
            
        return ans;
        }
};
