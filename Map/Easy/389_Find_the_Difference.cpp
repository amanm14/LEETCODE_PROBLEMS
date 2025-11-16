class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>smap;

        for(int i=0;i<t.length();i++){
            smap[s[i]]++;
            
        }
        for(int i=0;i<t.length();i++){
            if(smap.find(t[i])!=smap.end()){
                if(smap[t[i]]<=0) return t[i];
                smap[t[i]]--;
               
            } 
            else return t[i];
        }
        return t[0];
    }
};
