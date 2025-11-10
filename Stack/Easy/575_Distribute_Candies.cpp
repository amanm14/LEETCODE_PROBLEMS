class Solution {
public:
    int distributeCandies(vector<int>& candyType) { //TC O(N) SC O(N)
        map<int,int>mp;
        for(int i=0;i<candyType.size();i++){
            mp[candyType[i]]++;
        }
        cout<<mp.size()<<" size "<<endl;
       if(mp.size()>(candyType.size()/2)) return candyType.size()/2;
       else return mp.size();
    }
}
