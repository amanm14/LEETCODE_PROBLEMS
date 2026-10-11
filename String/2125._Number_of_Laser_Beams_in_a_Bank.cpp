// class Solution {
// public://O(N^4) is tc and it could be done in O(n^2) using prev and curr one method
//     int numberOfBeams(vector<string>& bank) {
//         int ans=0;
//         int m=bank.size();
//         int n=bank[0].size();
//         for(int i=0;i<bank.size();i++)
//         {
//             // if(bank[i])
//             for(int j=0;j<bank[i].size();j++)
//             {
//                 if(bank[i][j]=='0') continue;
//                 for(int k=i+1;k<m;k++)
//                 {
//                     int t=ans;
//                     for(int i1=0;i1<n;i1++)
//                     {
//                         if(bank[k][i1]=='1'){
//                             ans++;
//                         // cout<<"hello "<<endl;
//                         }
//                     }
//                     if(t!=ans) break;
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public://O(m*n)
    int numberOfBeams(vector<string>& bank) {
        int p=0;
        int c=0;
        int ans=0;
        for(int i=0;i<bank.size();i++)
        {
            c=0;
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1') c++;
            }
            if(c==0) continue;
            if(p!=0) ans+=p*c;
            p=c;
        }
        return ans;
    }
};
