class Solution {
public://O(N) is sc and tc 
    vector<int> rearrangeArray(vector<int>& nums) {
        int x=0;
        int y=0,idx1=0,idx2=0,n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(x==0&&nums[i]>0)
            {
                x=nums[i];
                idx1=i;
            }
            else if(y==0 && nums[i]<0)
            {
                y=nums[i];
                idx2=i;
            }
            else
            {
                continue;
            }
        }
        vector<int>ans;
        ans.push_back(nums[idx1]);
        ans.push_back(nums[idx2]);
        idx1++;
        idx2++;
        while(idx1<n&&idx2<n)
        {
            
            while(idx1<n&&nums[idx1]<0)
            {
                idx1++;
            }
            if(idx1<n) ans.push_back(nums[idx1++]);
            while(idx2<n&&nums[idx2]>0){
                idx2++;
            }
            if(idx2<n) ans.push_back(nums[idx2++]);
        }
        return ans;
    }
};
