// class Solution {
// public://O(n2)  tc 
//     int countCompleteDayPairs(vector<int>& hours) {
//         int count=0;
//         for(int i=0;i<hours.size();i++)
//         {
            
//             for(int j=i+1;j<hours.size();j++)
//             {
//                 if((hours[i]+hours[j])%24==0)
//                 {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

//O(Nlog24) tc and sc is O(24) as we can possibly sstore only 24 values in the map 
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int cnt = 0;
        int n = hours.size();
        map<int, int> mp;
        for(int i=0;i<n;i++){
            int hash = (24 - hours[i]%24)%24;
            if(mp.find(hash) != mp.end()) cnt+=mp[hash];
            mp[hours[i]%24]++;
        }
        return cnt;
    }
};
