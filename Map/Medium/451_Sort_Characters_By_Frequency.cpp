// class Solution {
// public://O(n+Nlogk) is tc and O(N) is sc
//     string frequencySort(string s) {
//         unordered_map<char,int> freq;           //for frequency of characters
//         priority_queue<pair<int,char>> maxheap; //maxheap according to frequency of characters
//         for(char c: s)
//             freq[c]++;
//         for(auto it: freq)
//             maxheap.push({it.second,it.first}); //heap will be constructed on the basis of frequency
//         s="";   
//         while(!maxheap.empty()){
//             s+=string(maxheap.top().first,maxheap.top().second); //frequency times the character
//             maxheap.pop();
//         }
//         return s;
//     }
// };
class Solution {
public://O(n+Nlogk) is tc and O(N) is sc
    string frequencySort(string s) {
       map<char,int>mpp;
       int n=s.size();
       for(int i=0;i<n;i++){
        mpp[s[i]]++;
       } 
       string ans;
       for(int i=n;i>=1;i--){
        for(auto it:mpp){
            if(it.second==i){
                for(int i=0;i<it.second;i++)
            ans+=it.first;}
        }
       }
  return ans;  }
};
