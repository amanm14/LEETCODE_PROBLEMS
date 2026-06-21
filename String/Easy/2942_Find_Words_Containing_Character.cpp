class Solution {
public://O(n*m) is tc and O(n) is sc
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int>ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(words[i][j]==x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
