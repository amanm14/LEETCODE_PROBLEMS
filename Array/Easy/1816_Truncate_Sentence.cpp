class Solution {
public://O(k) wjere k i slength till we reach k sppace chaar in string
    string truncateSentence(string s, int k) {
        int i=0,j=0;
        while(i<k&&j<s.size())
        {
            if(s[j]==' '){
                i++;
            }
            j++;
        }
        if(j!=s.size())j=j-1;
        return s.substr(0,j);
    }
};
