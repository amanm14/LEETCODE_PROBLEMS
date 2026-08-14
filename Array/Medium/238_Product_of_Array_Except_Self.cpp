class Solution {
public://O(n) is tc and o(n) is sc
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        
        int prod=1;
       
        for(auto i:nums)
        {
            if(i!=0)  prod*=i;
        }
        // int ptemp=prod;
        // for(int i=0;i<nums.size();i++){
        //     int temp=nums[i];
        //     ptemp=prod;
        //     if(temp==0)
        //     {
        //         ans.push_back(prod);
        //     }
        //     else{
        //         ptemp=ptemp/temp;
        //         cout<<ptemp<<endl;
        //         ans.push_back(ptemp);
        //     }
        // }

        int cntZ=0;
        // for(int i=0;i<nums.size();i++)
        // {
        //     int p=1;
        //     for(int j=0;j<nums.size();j++)
        //     {
        //         if(i!=j) p*=nums[j];
        //     }
        //     ans.push_back(p);
        // }
        int ptemp=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0) cntZ++;
        }
        if(cntZ>1){
            for(auto i:nums) ans.push_back(0);
        }
        else if(cntZ==1){
            for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            ptemp=prod;
            if(temp==0)
            {
                ans.push_back(prod);
            }
            else{
                
                ans.push_back(0);
            }
        }
        }
        else{
            for(int i=0;i<nums.size();i++)
            {
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }
};
