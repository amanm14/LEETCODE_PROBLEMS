class Solution {
public://O(Nlogn) is tc and O(N) is sc
    int findLucky(vector<int>& arr) {
        int n=arr.size();
        map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==mp[arr[i]]){
                ans=max(ans,arr[i]); 
            }
        }
        if(ans!=-1) return ans;
        return -1;
    }
};
