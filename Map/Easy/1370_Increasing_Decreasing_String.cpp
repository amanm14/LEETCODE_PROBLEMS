class Solution {
public:
    string sortString(string s) { //O(N2logn) is tc and O(N) is sc but as it is only small alphabater so its tc is O(Nlogn) its optimal complexity is O(N) tc and O(1) sc 
        map<char,int>mp; //O(Nlogn)
        sort(s.begin(),s.end());//O(nlogn)
        for(int i=0;i<s.length();i++){ //O(N)
            mp[s[i]]++;
        }
        string ans="";
        for(int i=0;i<s.length();i++){ // O(N2)
            string z ="";
            for(auto i:mp){
                char x=i.first;
                if(mp[x]>0)z+=x;
                mp[x]--;
            }
            if(i%2!=0) reverse(z.begin(),z.end());
            if(z.length()>0)ans+=z;
        }
        return ans;
    }
};
