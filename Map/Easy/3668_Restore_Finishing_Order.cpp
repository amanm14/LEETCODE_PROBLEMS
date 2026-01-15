class Solution {
public://O(nlogn) tc and sc is O(n)
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<friends.size();i++) mp[friends[i]]++;
        for(int i=0;i<order.size();i++)
        {
            if(mp[order[i]]>0) ans.push_back(order[i]);
        }
        return ans;
    }
};
