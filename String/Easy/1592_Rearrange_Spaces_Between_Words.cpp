class Solution {
public://0(n) is tc and sc is 0(n)
    string reorderSpaces(string text) {
        int totalSpaces = count(text.begin(), end(text), ' ');
        
        stringstream ss(text);
        vector<string> words;
        
        while(ss >> text){
            words.emplace_back(text);
        }
        
        if(words.size() == 1) return words[0] + string(totalSpaces, ' ');
        
        int spaces = totalSpaces/(words.size() - 1);
        int extraSpace = totalSpaces%(words.size() - 1);
        
        string ans = "";        
        
        for(int i = 0; i < words.size(); i++){
            ans += words[i];
            
            if(i != words.size() - 1){
                ans += string(spaces, ' ');
            }
        }
        
        ans += string(extraSpace, ' ');
        return ans;
    }
};
