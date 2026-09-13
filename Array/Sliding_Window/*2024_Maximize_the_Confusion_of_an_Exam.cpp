// class Solution {
// public:
//     int maxConsecutiveAnswers(string ansKey, int k) {
        
//         // for(int i=0;i<answerKey.size();i++) // total naive approach passed 43 testcases
//         // {
//         //     if(answerKey[i]=='T') ct++;
//         //     else cf++;
//         // }
//         // if(cf<ct){
//         //     int i=0,j=0;
//         //     while(j<answerKey.size())
//         //     {
//         //         // int j=i;
//         //         bool f=false;
//         //         while(k>0&&answerKey[j]=='F'&&j<answerKey.size())
//         //         {
//         //             answerKey[i]='T';
//         //             k--;
//         //             j++;
//         //             f=true;
//         //         }
//         //         while(answerKey[j]=='T'&&j<answerKey.size()) j++;
//         //         ans=max(ans, j-i);
//         //         if(k==0)
//         //         {
//         //             k=temp;
//         //             i=j;
//         //         }
//         //         // i=j+1;
                

//         //     }
//         // }
//         // else if(cf==ct)
//         // {
//         //     int i=0,j=0;
//         //     string t=answerKey;
//         //     while(j<answerKey.size())
//         //     {
//         //         // int j=i;
//         //         bool f=false;
//         //         while(k>0&&answerKey[j]=='F'&&j<answerKey.size())
//         //         {
//         //             // answerKey[j]='T';
//         //             k--;
//         //             j++;
//         //             f=true;
//         //         }
//         //         // int dk=j-1;
//         //         while(answerKey[j]=='T'&&j<answerKey.size()) j++;
//         //         ans=max(ans, j-i);
//         //         if(k==0)
//         //         {
//         //             k=temp;
//         //             i=j-1;
//         //         }
//         //         // i=j+1;
                

//         //     }
//         //     int a1=ans;
//         //     i=0;
//         //     j=0;
//         //     ans=INT_MIN;
//         //     answerKey=t;
//         //     k=temp;
//         //     while(j<answerKey.size())
//         //     {
//         //         // int j=i
//         //         // ;
//         //         bool f=false;
//         //         while(k>0&&answerKey[j]=='T'&&j<answerKey.size())
//         //         {
//         //             answerKey[j]='F';
//         //             k--;
//         //             j++;
//         //             f=true;
//         //         }
//         //         // int dk=j-1;
//         //         while(answerKey[j]=='F'&&j<answerKey.size()) j++;
//         //         ans=max(ans, j-i);
//         //         cout<<j<<" "<<i <<" ans "<<ans<<" k "<<k<<endl;
//         //         // i=j+1;
//         //         if(k==0){
//         //             k=temp;
//         //             i=j-1;
//         //         }
                

//         //     }
//         //     cout<<ans<<" "<<a1<<" "<<endl;
//         //     ans=max(a1,ans);
//         // }
//         // else{
//         //     // int i=0;
//         //     int i=0,j=0;
//         //     while(j<answerKey.size())
//         //     {
//         //         // int j=i
//         //         // ;
//         //         bool f=false;
//         //         while(k>0&&answerKey[j]=='T'&&j<answerKey.size())
//         //         {
//         //             answerKey[i]='F';
//         //             k--;
//         //             j++;
//         //             f=true;
//         //         }
//         //         while(answerKey[j]=='F'&&j<answerKey.size()) j++;
//         //         ans=max(ans, j-i);
//         //         // i=j+1;
//         //         if(k==0){
//         //             k=temp;
//         //             i=j;
//         //         }
                

//         //     }
//         // }
//         // return ans;
//         int temp=k,ans=INT_MIN;
//         int j=0;
//         for(int i=0;i<ansKey.size()&&j<ansKey.size();i++){
            
//             while(ansKey[j]=='T') j++;
//             cout<<j<<endl;
//             while(k>0&&ansKey[j]=='F'&&j<ansKey.size())
//             {
//                 k--;
//                 j++;
//             }
//              while(ansKey[j]=='T') j++;
//              cout<<j<<" "<<i<<" "<<k<<endl;
//             ans=max(ans,j-i);
//             if(k==0)
//             {
//                 k=temp;
//                 j=i;
//             }
//         }
//         int a1=ans;
//         ans=INT_MIN;
//         j=0;
//         for(int i=0;i<ansKey.size()&&j<ansKey.size();i++){
//             // j=i;
//             while(ansKey[j]=='F') j++;
//             while(k>0&&ansKey[j]=='T'&&j<ansKey.size())
//             {
//                 k--;
//                 j++;
//             }
//            while(ansKey[j]=='F') j++;
//             ans=max(ans,j-i);
//             if(k==0)
//             {
//                 k=temp;
//                 j=i;
//             }
//         }
//         cout<<ans<<" "<<a1<<" "<<endl;
//         ans=max(a1,ans);
//         return ans;
//     }
// };

class Solution {
public://O(n) is tc and O(1) is sc one time we assume all true and count window of t by reducing false and increasing simulatneously and second time we assume it to all false
    int maxConsecutiveAnswers(string ansKey, int k) {
        int n = ansKey.size();
        int ans = 0;

        // Make everything T
        int i = 0, cnt = 0;

        for(int j = 0; j < n; j++) {

            if(ansKey[j] == 'F')
                cnt++;

            while(cnt > k) {
                if(ansKey[i] == 'F')
                    cnt--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        // Make everything F
        i = 0;
        cnt = 0;

        for(int j = 0; j < n; j++) {

            if(ansKey[j] == 'T')
                cnt++;

            while(cnt > k) {
                if(ansKey[i] == 'T')
                    cnt--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
