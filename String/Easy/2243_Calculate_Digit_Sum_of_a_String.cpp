// class Solution {
// public://O(n) is tc and sc
//     string digitSum(string s, int k) {
//         // string ans="",z="";
//         // int n=s.length();
//         // int K=k,aa=0;
//         // int i=0;
//         // while(s.length()>K)
//         // {
//         //     if(k==0){
//         //         k=K;
//         //         while(aa>0){
//         //             char c=aa%10+'0';
//         //             aa=aa/10;
//         //              ans.push_back(c);
//         //         }
                
//         //     }
//         //     if(i>=n){
//         //         i=0;
//         //         s=ans;
//         //         z=ans;
//         //         ans="";
//         //         aa=0;
//         //     }
//         //     char ch=(s[i++]-'0');
//         //     aa=aa+ch;
//         //     k--;
//         // }
        
//         // return s;
//         while (s.length() > k) {
//     string ans = "";

//     for (int i = 0; i < s.length(); i += k) {
//         int sum = 0;
//         for (int j = i; j < min(i + k, (int)s.length()); j++) {
//             sum += s[j] - '0';
//         }
//         ans += to_string(sum);
//     }

//     s = ans;
// }

// return s;
//     }
// };
class Solution {
public:
    string digitSum(string s, int k) {

        int K = k;

        while (s.length() > K) {

            string ans = "";
            int aa = 0;
            int cnt = 0;

            for (int i = 0; i < s.length(); i++) {

                aa += s[i] - '0';
                cnt++;

                if (cnt == K || i == s.length() - 1) {
                    ans += to_string(aa);
                    aa = 0;
                    cnt = 0;
                }
            }

            s = ans;
        }

        return s;
    }
};
