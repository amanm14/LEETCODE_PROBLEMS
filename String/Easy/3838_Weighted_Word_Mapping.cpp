class Solution {
public://O(n*m) w3here n is number of words and m is lenggth of th e words and sc is O(st.length())
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int ans=0;
        string st="";
        for(int i=0;i<words.size();i++)
        {
            int x=0;
            for(int j=0;j<words[i].length();j++)
            {
                x+=weights[words[i][j]-'a'];
            }
            x=x%26;
            // cout<<x<<"  "<<26-x<<" "<<endl;
            st.push_back(abs(26-x-1)+'a');
        }
        return st;
    }
};
