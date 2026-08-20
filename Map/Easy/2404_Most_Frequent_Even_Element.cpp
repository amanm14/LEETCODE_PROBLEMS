class Solution {
public://tc is O(n*logn) and sc is O(n)
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                mp[nums[i]]++;
            }
        }
    
    pair<int,int>ans;
    ans.first=-1;
    ans.second=0;
    for(auto i:mp)
    {
        if(i.second>ans.second)
        {
            ans.first=i.first;
            ans.second=i.second;
        }
    }
    return ans.first;
    }
};
