class Solution {
public://O(n) is tc and sc
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        vector<char>a(indices.size());
        for(int i=0;i<indices.size();i++)
        {
            a[indices[i]]=s[i];
        }
        for(auto it:a) ans+=it;
        return ans;
    }
};
