class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 1; //O(n) is tc and O(1) is sc and we are using Boyer–Moore Majority Vote Algorithm
        int count1 = 0, count2 = 0;

        for (int num : nums) {

            if (num == candidate1)
                count1++;

            else if (num == candidate2)
                count2++;

            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }

            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }

            else {
                count1--;
                count2--;
            }
        }

        count1 = count2 = 0;

        for (int num : nums) {
            if (num == candidate1)
                count1++;
            else if (num == candidate2)
                count2++;
        }

        vector<int> ans;

        if (count1 > nums.size() / 3)
            ans.push_back(candidate1);

        if (count2 > nums.size() / 3)
            ans.push_back(candidate2);

        // return ans;


        // int n=nums.size();//O(n) is tc and sc
        // vector<int>ans;
        // unordered_map<int,int>mp;
        // for(auto it:nums)
        // {
        //     mp[it]++;
            
        // }
        // for(auto it:mp){
        //     if(it.second>(n/3))
        //     {
        //         ans.push_back(it.first);
        //         it.second=-1;
        //     }
        // }


        // bool flag=false;//O(n2) is tc and sc is O(n)
        // int indicator=nums[0]+1;
        // for(int i=0;i<n;i++)
        // {
        //     int cnt=0;
        //     if(flag==true&&nums[i]==indicator) continue;
        //     for(int j=0;j<n;j++)
        //     {
        //         if(nums[i]==nums[j]) cnt++;
                
        //     }
        //     if(cnt>(n/3))
        //     {
        //         // cout<<" i "<<i<<endl;
        //         // cout<<"cnt "<<cnt<<endl;
        //         // cout<<nums[i]<<endl;
        //         ans.push_back(nums[i]);
        //     }
        //     if(flag==false)
        //     {
        //         flag=true;
        //         indicator=nums[i];
        //     }
        //     int initialValue=nums[i];
        //     for(int j=0;j<n;j++)
        //     {
        //         if(nums[j]==initialValue)
        //         {
        //             nums[j]=indicator;
        //         }
        //     }
        //     // for(auto it:nums) cout<<it<<" ";
        // }
        return ans;
    }
};
