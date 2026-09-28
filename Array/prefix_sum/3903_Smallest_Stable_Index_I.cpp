class Solution {
public://O(N) is tc and sc
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=INT_MAX;
        vector<int>a1;
        vector<int>a2;
        int ma=INT_MIN;
        int mi=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            ma=max(nums[i],ma);
            // mi=min(nums[i],mi);
            a1.push_back(ma);
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            mi=min(nums[i],mi);
            // mi=min(nums[i],mi);
            a2.push_back(mi);
        }
        for(int i=0;i<a1.size();i++)
        {
            int z=abs(a1[i]-a2[a1.size()-(i+1)]);
            // cout<<a1[i]<<" "<<a2[i]<<endl;
            if(z<=k) return i;
        }
        return -1;
    }
};
