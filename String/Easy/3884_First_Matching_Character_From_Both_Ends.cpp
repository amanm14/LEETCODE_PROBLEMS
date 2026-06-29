class Solution {
public://O(n) is tc and O(1) is sc
    int firstMatchingIndex(string s) {
        int x=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
                if(s[i]==s[s.length()-i-1]){
                        return i;
                    
                } 
        }
        return -1;
    }
};
