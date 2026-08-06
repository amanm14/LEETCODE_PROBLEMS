class Solution {
public://O(n^3) is tc and O(k) is sc where k is total quadrilateral 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i=0;
        int j=i+1;
        int k=j+1;
        int l=nums.size();
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(i<nums.size())
        {
            j=i+1;
            // vector<int>temp;
            if(i>0 && nums[i]==nums[i-1]){
                i++;
                continue;
            }
            while(j<nums.size())
            {
                k=j+1;
                l=n-1;
                if(j>i+1 && nums[j]==nums[j-1]){
                    j++;
                    continue;
                }
                while(k<l)
                {
                        long long sum=1LL*nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target)
                        {
                            ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                            l--;
                            k++;
                            while(k<l&&nums[k]==nums[k-1]) k++;
                            while(k<l&&nums[l]==nums[l+1]) l--;
                        }
                        else if(sum<target)
                        {
                            k++;
                        }
                        else{
                            l--;
                        }
                    
                }
                j++;
                // ans.push_back(temp);
            }
            i++;
        }
        return ans;
    }
};
