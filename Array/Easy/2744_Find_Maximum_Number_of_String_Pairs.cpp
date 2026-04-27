class Solution {
public://O(klogk) is tc and O(n^2) is sc
    int maximumNumberOfStringPairs(vector<string>& words) {
        int count = 0;
        
        for(int i = 0; i < words.size(); i++){
            string s1 = words[i];                 
            sort(s1.begin(), s1.end());  
            for(int j = i+1; j < words.size(); j++){
                string s2 = words[j];                 
                sort(s2.begin(), s2.end());
                if(s1 == s2){
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};
