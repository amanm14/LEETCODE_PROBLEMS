class Solution {
public://O(n2) is tc and O(1) is sc
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int i=0;
        
        while(i<nums.size())
        {
            // int sum=nums[i];
            int sum=0;
            int j=i+1;
            int k=nums.size()-1;
            if (i > 0 && nums[i] == nums[i - 1]){i++;continue;}
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    // if(check(nums[i],nums[j],nums[k],ans)==false) 
                    ans.push_back({nums[i],nums[j],nums[k]});
                     
                     j++;
                     k--;
                      // skip duplicates
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if(sum<0) j++;
                else k--;
            }
            i++;
        }
        return ans;
    }
    // bool check(int a,int b,int c,vector<vector<int>>nums) //O(n4) time  complexity which is bad
    // {
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         if(nums[i][0]==a&&nums[i][1]==b&&nums[i][2]==c) return true;
    //     }
    //     return false;
    // }
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     int i=0;
    //     sort(nums.begin(),nums.end());
    //     vector<vector<int>>ans;
    //     int k=i+1;
    //     int j=1;

    //     while(i<nums.size()){
    //         j=i+1;
    //         while(j<nums.size()){
    //             k=j+1;
    //             while(k<nums.size()){
    //                 if(i!=j&&j!=k&&i!=k){
    //                 // cout<<"hello ";
    //                 // cout<<nums[i]+nums[j]+nums[k]<<" ";
    //                 if((nums[i]+nums[j]+nums[k])==0){
                        
    //                     if(check(nums[i],nums[j],nums[k],ans)==false)ans.push_back({nums[i],nums[j],nums[k]});
                        
    //                 }
    //                 }
    //                 k++;
    //             }
    //             j++;
                
    //         }
    //         i++;
    //         k++;
    //     }

    //     //     j=i+1;
    //     //     while(j<nums.size())
    //     //     {
    //     //         if(i!=j&&j!=k&&i!=k){
    //     //             // cout<<"hello ";
    //     //             // cout<<nums[i]+nums[j]+nums[k]<<" ";
    //     //             if((nums[i]+nums[j]+nums[k])==0){
                        
    //     //                 ans.push_back({nums[i],nums[j],nums[k]});
                        
    //     //             }
    //     //         }
    //     //         j++;
    //     //     }
    //     //     // i++;
    //     //     // k--;
    //     //         // if(i!=j&&j!=k&&i!=k){
    //     //         //     // cout<<"hello ";
    //     //         //     // cout<<nums[i]+nums[j]+nums[k]<<" ";
    //     //         //     if((nums[i]+nums[j]+nums[k])==0){
                        
    //     //         //         ans.push_back({nums[i],nums[j],nums[k]});
                        
    //     //         //     }
    //     //         // }
    //     //         if(nums[i]+nums[j]+nums[k]<0){
    //     //             i++;
    //     //             // j++;
    //     //         }
    //     //         else if(nums[i]+nums[j]+nums[k]>0){
    //     //             k--;
    //     //         }
    //     //         else{
    //     //             i++;
    //     //             // j++;
    //     //             k--;
    //     //         }

    //     // }
    //     return ans;
    // }
};
