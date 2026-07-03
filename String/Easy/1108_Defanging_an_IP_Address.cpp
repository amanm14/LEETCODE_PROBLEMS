class Solution {
public://O(n) is tc and
    // Auxiliary Space (excluding output): 
// O(1)
// Total Space (including output): 
// O(n)

    string defangIPaddr(string address) {
        string ans="";
        
        for(auto it:address){
            if(it=='.'){
                ans.push_back('[');
                ans.push_back('.');
                ans.push_back(']');
            }
            else ans.push_back(it);
        }
        return ans;
    }
};
