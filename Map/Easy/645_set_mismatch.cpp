class Solution {
public://O(nlogn) is tc and O(n) is sc
    vector<int> findErrorNums(vector<int>& nums) {

        map<int,int>mp;
        vector<int>ans;

        int cnt=1;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1){
                ans.push_back(nums[i]);
            }
        }

        bool flag=false;
        for(auto i:mp)
        {
            if(i.first!=cnt){
             ans.push_back(cnt);
             flag=true;
             break;
            }
            cnt++;

        }

        if(flag==false){
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
