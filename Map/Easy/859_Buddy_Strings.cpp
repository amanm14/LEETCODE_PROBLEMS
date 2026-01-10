class Solution {
public: //O(nlog k) k is the char that we are pushing since it is alphabet which can only be 26 types so logK is constant so overall tc is O(n) also with the same logic the space complexity is O(1)
    bool buddyStrings(string s, string goal) {
        map<char,int>mp;
        // if(s==goal) return true;
        if(s.length()!=goal.length()) return false;
        int x=-1;
        int y=-1;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            if(s[i]!=goal[i])
            {
                if(x!=-1&&y!=-1) return false;
                else if(x==-1) x=i;
                else y=i;
            }
        }
        map<char,int>mp2;
        for(auto i:mp) mp2[i.first]=i.second;
        for(int i=0;i<goal.length();i++){
            
            if(mp2[goal[i]]<=0) return false;
            cout<<"hello "<<mp2[goal[i]];
            mp2[goal[i]]--;
        }
        if(x!=-1&&y!=-1) return true;
        else if(x==-1&&y==-1){
            for(auto i:mp){
                if(i.second>=2){
                    return true;
                }
            }
            return false;
        }
        return false;
    }
};
