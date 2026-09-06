// class Solution {
// public://not slding window tc is O(n^2) as i is getting reset to j repeatedly
//     int countKConstraintSubstrings(string s, int k) {
//         int cz=0,j=0,i=0;
//         int co=0;
//         int t=0;
//         while(j<s.length())
//         {
//             if(i>=s.length()){
//                 j++;
//                 i=j;
//                 // cout<<" t "<<t<<endl;
//                 // cout<<" co "<<co<<" cz "<<cz<<endl;
//                 cz=0;
//                 co=0;
                
//             }
//             if(s[i]=='0') cz++;
//             if(s[i]=='1') co++;
//             if(cz>k&&co>k)
//             {
//                 // cout<<" t "<<t<<endl;
//                 cz=0;
//                 co=0;
//                 j++;
//                 i=j;
//             }
//             else{
//                 i++;
//                 t++;
//             }
            
//         }
//         return t-1;
//     }
// };

class Solution {
public://sliding window O(n) tc approach here they are calculating the window once zero and 1 is > k simple idea
    int countKConstraintSubstrings(string s, int k) {
        int n=s.size();
        int l=0, r=0,zeroes=0,ones=0,ans=0;
        while(r<n){
          if(s[r]=='0')zeroes++;
            else ones++;
            while(zeroes>k and ones>k){
                if(s[l]=='0') zeroes--;
                else ones--;
                l++;
            }
            ans+=r-l+1;
            r++;
            
        }
        return ans;
        
    }
};
