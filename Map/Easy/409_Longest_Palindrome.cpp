class Solution {
public:
// O(N) is time but space is O(1) as we are storing only fixed no. of char so space would become constant
    // we can intialize a array of 128 size and stoe char at idx and run the loop logic of this code on that arr
    int longestPalindrome(string s) {
        int check=0,ans=0;
        // transform(s.begin(),s.end(),s.begin(),::tolower);
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
            int cal=i.second;
            
            if(cal%2==0)ans=ans+cal;
            else{ 
                ans=ans+cal-1;
                check=1;
            }
        }
        if(mp.size()==1) return mp[s[0]];
        else if(check==1){
            return ans+1;
        }

        return ans;

    }
};
