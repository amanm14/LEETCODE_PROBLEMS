// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         //check 3 elements if any of them contain 0 or not 
//         // if not then move window by one and keep checking if next element is zero or not 
//         // if zero check for correct combination to reach end by converting evry element to 1 just move the first index to the zero element 

//         int sidx=0;
//         int eidx=2;
//         int i=0;
//         int ans=0;
//         while(i<3)
//         {
//             if(nums[i]==0)
//             {
//                 sidx=i;
//                 eidx=i+2;
//                 break;
//             }
//             i++;
//         }
//         while(eidx<nums.size()){
//             if(nums[sidx]!=0){
//                 while(nums[sidx]!=0&&sidx<nums.size()) //first we need to define the size the comparision
//                 {
//                     sidx++;
//                     if(sidx+2<nums.size()&&nums[sidx]==0){
//                         eidx=sidx+2;
//                     }
//                     // else{
//                     //     // cout<<ans<<endl;
//                     //     return ans;
//                     // }
//                 }
                
//             }
//             else
//             {
//                 int tidx=sidx;
//                 // cout<<nums[tidx]<<endl;
//                 nums[tidx++]=1;

//                 if(nums[tidx]==0) nums[tidx++]=1;
//                 else nums[tidx++]=0;

//                 if(nums[tidx]==0) nums[tidx++]=1;
//                 else nums[tidx++]=0;
//                 // cout<<nums[tidx-1]<<endl;

//                 eidx++;
//                 sidx++;
                
//                 ans++;
//             }
//         }
//         // cout<<ans<<endl;
//         for(int i:nums) if(i==0) return -1;
//         return ans;
//     }
// };

class Solution {
public://O(n) is tc and O(1) is sc
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                // Cannot flip 3 elements starting here
                if(i + 2 >= n)
                    return -1;

                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];

                ans++;
            }
        }

        return ans;
    }
};
