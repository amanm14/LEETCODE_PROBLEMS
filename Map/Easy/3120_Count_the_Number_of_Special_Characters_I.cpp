class Solution {
public:// tc is O(n) and sc O(1) as we have only 26 + 26 letters
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        for(int i=0;i<word.length();i++)
        {
            mp[word[i]]++;
        }
        int cnt=0;
        for(auto i:mp)
        {
            char y=i.first;
            char z=toupper(y);
            if(z==y) continue;
            else if(mp[z]>0){
                cnt++;
            }
        }
        return cnt;
    }
};
