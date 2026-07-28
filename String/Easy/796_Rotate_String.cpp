// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         char a=s[0],b=goal[s.length()-1];
//         int i=0,j=s.length()-1;
//         if(goal.length()==1&&goal[0]!=s[0]) return false;
    
//         while(a!=b&&j>0){
//             j--;
//             b=goal[j];
//             //  cout<<" h "<<j<<endl;
//         }
//          if(j==goal.length()-1){
//                  j=0;
//                  i++;
//                  a=s[i];
//                  b=goal[j];
//                 //  cout<<" h "<<j<<endl;
//             }
//         while(a==b)
//         {
//             i++;
//             j++;
//             if(j>=goal.length()){
//                  j=0;
//                 //  cout<<" h "<<j<<endl;
//             }
//             a=s[i];
//             b=goal[j];
//             // cout<<a<<" "<<b<<" i and j"<<i<<" "<<j<<endl;

//         }
//         if(i==goal.size()) return true;
//         return false;
//     }
// };

class Solution {
public://O(N) is tc and sc
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};
