class Solution {
public://O(n) is tc and O(1) is sc
    int removeAlmostEqualCharacters(string word) {
        int cnt=0;
        for(int i=1;i<word.length();i++){
            char t2=word[i-1]+1;
            char t=word[i]+1;
            if(t==word[i-1]&&i++) cnt++;
            else if(word[i-1]==word[i]&&i++) cnt++;
            else if(t2==word[i]&&i++) cnt++;
            else continue;
            
        }
        return cnt;
    }
};
