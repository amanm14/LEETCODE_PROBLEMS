class Solution {
public://Time = O((n + q) log n)
//O(n + q)
// n = nums.size()

// q = queries.size()

// k = number of times x appears (k ≤ n)

    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        map<int,int>mp;
        int cnt=1;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==x){
            mp[cnt]=i;
            cnt++;
           }
        }
        vector<int>ans;

        for(int i=0;i<queries.size();i++)
        {
            int z=queries[i];
            if((cnt-1)<z)
            {
                ans.push_back(-1);
            }
            else{
                ans.push_back(mp[z]);
                // int j=0;//Time limit exceed
                // while(z>0)
                // {
                //     if(nums[j]==x)
                //     {
                //         z--;
                //     }
                //     j++;
                // }
                // ans.push_back(--j);
            }
        }
        return ans;
    }
};
