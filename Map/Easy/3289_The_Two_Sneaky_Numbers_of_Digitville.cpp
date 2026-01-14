class Solution {
public://tc is O(n) and sc is O(nlogn)
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int size=nums.size();
        vector<int>ans;//O(n)
        map<int,int>mp;//O(n)
        for(int i=0;i<size;i++) //O(n)
        {
            if(mp[nums[i]]>0){
                ans.push_back(nums[i]);
            }
            else mp[nums[i]]++;//(logn)
        }
        return ans;

    }
};
