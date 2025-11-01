class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    //     unordered_map<char,int>mp;
    //     for(char c:magazine){
    //         mp[c]++;
    //     }
    //     for(char c:ransomNote){
    //         if(mp.find(c)!=mp.end()&&mp[c]!=0){
    //             mp[c]--;
    //         }
    //         else return false;

    //     }
    //     return true; //O(nlogn) tc and sc is O(n)
     int counter[26] = {0};
        // Traverse a loop through the entire String of magazine where char ch stores the char at the index of magazine...
        for(char ch : magazine)
            counter[ch - 'a']++;
        // Run another for loop for ransomNote...
        for(char ch : ransomNote)
            // If the charachter doesn't exists in magazine for ransomNote, we return false...
            if(counter[ch - 'a']-- <= 0)
                return false;
        return true;      
    }
};
