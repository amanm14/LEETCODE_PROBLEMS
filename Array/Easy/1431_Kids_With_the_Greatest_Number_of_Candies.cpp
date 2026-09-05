class Solution {
public://O(n) tc and sc
    vector<bool> kidsWithCandies(vector<int>& candies, int e) 
    {
        int g=INT_MIN;
        vector<bool>ans;
        for(auto i:candies) g=max(g,i);
        for(int i=0;i<candies.size();i++)
        {
            if(e+candies[i]>=g){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};
