class Solution {
public://O(n) is tc and sc is O(1)
    bool checkIfPangram(string sentence) {
        vector<bool>a(26,0);
        for(int i=0;i<sentence.length();i++)
        {
            // 
            a[sentence[i]-'a']=1;
        }
        for(auto i:a) if(i==0) return 0;
        return 1;
    }
};
