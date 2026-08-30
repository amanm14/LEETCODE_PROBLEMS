class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // int ans=0;//O(n^2) is tc TLE
        // int temp=0;
        // for(int i=0;i<arr.size();i++)
        // {
        //     temp=0;
        //     for(int j=i;j<arr.size();j++)
        //     {
        //         temp+=arr[j];
        //         if(temp/(j+1-i) >= threshold && k==j+1-i) ans++;
        //     }
        // }
        // return ans;


        //O(n) is tc and O(1) is sc
        int i=0,temp=0,ans=0;
        int j=0;
        while(i<arr.size()&&j<arr.size())
        {
            // cout<<i<<" i "<<arr[i]<<" "<<j<<" j "<<arr[j]<<endl;
            temp+=arr[j];
            // cout<<"j "<<j<<" temp "<<temp<<" average "<<(temp/(j+1-i))<<endl;
            // cout<<j-i+1<<endl;
            // cout<<temp/(j-i+1)<<endl;
            if(j-i+1==k && (temp/(j+1-i)) >= threshold)
            {
                // cout<<" hello ";
                ans++;
                temp-=arr[i];
                i++;
            }
            else if(j-i+1==k && temp/(j+1-i) < threshold)
            {
                // cout<<" hi ";
                temp-=arr[i];
                i++;
            }
            j++;
            
        }
        return ans;
    }
};
