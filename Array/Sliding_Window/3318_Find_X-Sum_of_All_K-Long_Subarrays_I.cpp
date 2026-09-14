class Solution {
public://O(n*k*x) is the tc and sc is O(k)
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        // for(int i=0;i<nums.size()-k;i++)
        // {
        //     map<int,int>mp;
        //     int j=i+k-1;
        //     int sum=0;
        //     while(j>0){
        //         mp[nums[j]]++;
        //         j--;
        //     }
        //     int t=x;
        //     while(t>0)
        //     {
        //         int m=0;
        //         int ma=0;

        //         for(auto i:mp)
        //         {
        //             // cout<<"Hello "<<endl;
        //             if(m<i.second){
        //                 m=i.second;
        //                 ma=i.first;
        //                 // cout<<"Hello "<<endl;
        //             }
        //         }
        //         sum+=ma;
        //         mp.erase(ma);
        //         t--;
        //     }
        //     ans.push_back(sum);
        // }
        map<int,int>mp;
        
        vector<int>ans;
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(i>=k-1)
            {
                
                // while(temp>0)
                // {
                    cout<<i<<endl;
                    int temp=x;
                    int ss=0,zz=0;
                    vector<bool>b(50,false);
                    while(temp>0)
                    {
                        int m=0;
                        ss=0;
                        for(auto j:mp)
                        {
                        // if(temp==0) break;
                            if(b[j.first]==false && m<=j.second)
                            {
                                m=j.second;
                                ss=j.first;
                            }
                        }
                        b[ss]=true;
                        // ans.push_back()
                        zz+=(m*ss);
                        temp--;
                    }
                    ans.push_back(zz);
                    mp[nums[s]]--;
                    s++;
                // }
            }
        }
        if(ans.size()==0)
        {
            int t=0;
            for(auto i:nums) t+=i;
            ans.push_back(t);
        }
        return ans;
    }
};
