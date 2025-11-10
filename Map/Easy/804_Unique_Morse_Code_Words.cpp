class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // TC O(n*L) SC O(n*L)
        string a[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // int a=sizeof(arr)/arr[0];
        map<char,string>mp;
        char z=97;
        int i=0;
        while(z<123){
            mp[z]=a[i];
            z++;
            i++;
        }

        map<string,int>mp1;
        for(int i=0;i<words.size();i++){
            string z=words[i];
            string ans="";
            for(int j=0;j<z.length();j++){
                ans+=mp[z[j]];
            }
            mp1[ans]++;
        }
        return mp1.size();
    }
};
