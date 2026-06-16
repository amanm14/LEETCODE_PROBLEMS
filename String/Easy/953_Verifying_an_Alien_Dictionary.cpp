
class Solution {
public://O(n*m) m is number of words and sc O(1) as there uis only 2 letter
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char,int> mp;

        for(int i=0;i<order.size();i++){
            mp[order[i]] = i;
        }

        for(int i=0;i<words.size()-1;i++){

            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.size(), s2.size());
            int j = 0;

            while(j < len && s1[j] == s2[j]){
                j++;
            }

            // All common characters matched
            if(j == len){
                if(s1.size() > s2.size())
                    return false;
            }
            else{
                if(mp[s1[j]] > mp[s2[j]])
                    return false;
            }
        }

        return true;
    }
};
