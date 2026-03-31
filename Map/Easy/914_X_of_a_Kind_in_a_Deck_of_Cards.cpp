class Solution {
public://O(nlogn) is tc and O(n)
//     int hcf(int a, int b) {
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
//     }
//     bool hasGroupsSizeX(vector<int>& deck) {
//         map<int,int>mp;
//         if(deck.size()<2) return false;
//         for(int i=0;i<deck.size();i++) mp[deck[i]]++;
//         // int x=mp[deck[0]];
//         // int s=INT_MAX;
//         // for(auto i:mp)
//         // {
//         //     s=min(s,i.second);
//         // }
//         bool e=false;
//         bool o=false;
//         for(auto i:mp)
//         {
//             // int c=hcf(i.second,x);
//             // cout<<c<<" c "<<i.second<<endl;
//             //     if(i.second!=x){
//             //         if(c==1) return false;

//             //     }
            
//             if(i.second%2==0) e=true;
//             else o=true;
//         }
//          int x=mp[deck[0]];
//         int s=INT_MAX;
//         for(auto i:mp)
//         {
//             s=min(s,i.second);
//         }
//         for(auto i:mp)
//         {
//             int c=hcf(i.second,x);
//             // cout<<c<<" c "<<i.second<<endl;
//                 if(i.second!=x){
//                     if(c==1) return false;

//                 }
//         }
//         if(e==true&&o==true) return false;
//         return true;
//     }

//O(Nlogn) is tc and O(n) is sc
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }
};
