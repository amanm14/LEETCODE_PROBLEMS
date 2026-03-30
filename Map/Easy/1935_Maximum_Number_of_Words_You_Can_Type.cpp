class Solution {
public://O(nlogn) and O(1) is sc
    int canBeTypedWords(string text, string brokenLetters) {
        map<char,int>mp;
        int cnt=0;
        for(int i=0;i<brokenLetters.size();i++) mp[brokenLetters[i]]++;
        for(int i=0;i<text.size();){
            bool flag=false;
            // char z=' ';
            while(i<text.size()&&text[i]!=' '){
                if(mp.count(text[i])){
                    flag=true;
                }
                i++;
            }
            i++;
            if(flag==false) cnt++;
        }
        return cnt;
    }
};
