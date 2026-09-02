class Solution {
public://O(nlogn) is tc and O(1) is sc
    vector<int> numberOfPairs(vector<int>& nums) {
       
        int cnt=0,cnt2=0;
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]){
                
                nums[i]=-1;
                nums[i-1]=-1;
                i++;
                cnt++;
            }
        }
        for(int i:nums) if(i!=-1) cnt2++;


        vector<int>ans;
        ans.push_back(cnt);
        ans.push_back(cnt2);
        return ans;
    }
};
