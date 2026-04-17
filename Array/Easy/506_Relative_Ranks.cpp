class Solution {
public://O(n*logn) is tc and O(n) is sc
    vector<string> findRelativeRanks(vector<int>& score) {

        
        vector<string>ans(score.size());

        unordered_map<int,int>mp;
        for(int i=0;i<score.size();i++)
        {
            mp[score[i]]=i;
        }
        sort(score.begin(),score.end());

        int j=score.size()-1;

        for(int i=score.size()-1;i>=0;i--)
        {
            if(i==score.size()-1){
                ans[mp[score[i]]]="Gold Medal";
            }
            else if(i==score.size()-2){
                ans[mp[score[i]]]="Silver Medal";
            }
            else if(i==score.size()-3){
                ans[mp[score[i]]]="Bronze Medal";
            }
            else{
                ans[mp[score[i]]]=to_string(score.size()-i);
            }

        }
        return ans;
    }
};
