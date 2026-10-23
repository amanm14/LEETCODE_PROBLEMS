class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int k=pref.length();
        int n=words.size(),cnt=0;
        for(int i=0;i<n;i++){
            // string t=words[i];
            // string t2=t.substr(0,k); //uses extra sc O(k) where k is len of t
            // if(t2==pref) cnt++;

            //both find() and compare uses O(1) sc
            // if(words[i].find(pref)==0) cnt++;

            if(words[i].compare(0,k,pref)==0) cnt++;
        }
        return cnt;
    }
};
