class Solution {
public://O(n) is tc and O(1) as sc as 26 letter only to store inn set
    int countKeyChanges(string s) {
        
        string ans="";
        int cnt=0;
        for(auto it:s){
            char z=tolower(it);
            ans.push_back(z);
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i]!=ans[i-1]) cnt++;
        }
        return cnt;
    }
};
