class Solution {
public://o(n) is tc as we are going only once to each char and s c is O(1)
    int mostWordsFound(vector<string>& sentences) {
        int ans=0;
        for(int i=0;i<sentences.size();i++)
        {
            int cnt=0;
            for(int j=0;j<sentences[i].length();j++)
            {
                if(sentences[i][j]==' ') cnt++;
            }
            ans=max(cnt+1,ans);
        }
        return ans;
    }
};
