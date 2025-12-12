class Solution {
public://O(NlogN) is TC and sc is O(N)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            // ans.push_back(arr2[i]);
            while(mp[arr2[i]]>0){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
            if(mp[arr2[i]]<=0){
                mp.erase(arr2[i]);
            }
        }
        for(auto i:mp){
            int size=i.second;
            while(size>0){
                ans.push_back(i.first);
                size--;
            }
        }
        return ans;
    }
};
