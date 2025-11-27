class Solution {
public: //O(N) tc nd sc
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp;
        vector<string>ans;
        string car="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]==' '){
                mp[car]++;
                car="";
            }
            else car=car+s1[i];
        }
        mp[car]++;
        car="";
        for(int i=0;i<s2.length();i++){
            if(s2[i]==' '){
                mp[car]++;
                car="";
            }
            else car=car+s2[i];//use push_back for O(N) tc
        }
        mp[car]++;
        car="";
        for(auto i:mp){
            if(i.second==1){
                ans.push_back(i.first);            
            }
        }
        return ans;
    }
};
