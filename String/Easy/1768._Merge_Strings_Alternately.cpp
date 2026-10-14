class Solution {
public://O(n+m) is tc and sc
    string mergeAlternately(string word1, string word2) {
        string a="";
        int n=max(word1.length(),word2.length());

        for(int i=0;i<n;i++)
        {
            if(i<word1.length()) a.push_back(word1[i]);
            if(i<word2.length())  a.push_back(word2[i])
        }
        return a;
    }
};
