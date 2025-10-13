// so overall TC is O(n) and SC is O(1) as we can only have 26 char, so we consider it as constant that which becomes O(1)
class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;//insertion at map takes O(logN) TC,  but here we can only have 26 char, so we consider it as constant that which becomes O(1)
        }
        int one=0;
        int two=0;
        for(auto i:mp){//finding max  at map takes O(K) TC,  but here we can only have 26 char, so we consider it as constant that it becomes O(1)
            char c=i.first;
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                one=max(one,i.second);
            }
            else{
                two=max(two,i.second);
            }
        }
        return one+two;
    }
};
