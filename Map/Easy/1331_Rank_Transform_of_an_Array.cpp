class Solution {
public://TC nd SC O(N)
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());
        int rank=1;
        for(int i = 0; i < copy.size(); i++){
            if(mp.find(copy[i]) == mp.end()){ // assign rank only first time
                mp[copy[i]] = rank;
                rank++;
            }
        }
        vector<int> ans;
        for(int k:arr){
            ans.push_back(mp[k]);
        }
        return ans;
    }
};
