class Solution {
public://O(n) is tc and sc
    vector<int> minCosts(vector<int>& cost) {
        vector<int>ans;
        ans.push_back(cost[0]);
        for(int i=1;i<cost.size();i++)
        {
            if(cost[i]<ans[i-1]){
                ans.push_back(cost[i]);
            }
            else ans.push_back(ans[i-1]);
        }
        return ans;
    }
};
