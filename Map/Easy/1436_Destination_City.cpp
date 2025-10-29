class Solution {//TC->O(NlogN) sc-> O(N)
public:
    string destCity(vector<vector<string>>& paths) {//using unordered map reduce time complexity to O(1) but if in worst case where collision happen and  different 
    // would have the same integer  from the hash function, then we will calculate their % with the bucket list. If two strings have the same integer, then a collision can occur 
    // In that case worst case happens, as now we have to traversethe whole bucket to prevent collision
        map<string,string>mp;
        for(int i=0;i<paths.size();i++){
            mp[paths[i][0]]=paths[i][1];// O(logN) as ordered map maintain order
        }
        string ans="";
        for(int j=0;j<paths.size();j++){
                string check=paths[j][1];
                if(mp.find(check)==mp.end()){// O(logN) as ordered map maintain order
                    ans=check;
                }
            }
        return ans;
    }
};
