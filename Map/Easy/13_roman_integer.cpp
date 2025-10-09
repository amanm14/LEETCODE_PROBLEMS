class Solution {
public:
    // int romanToInt(string s) {
    //     unordered_map<char,int>ump;
    //     ump['I']=1;
    //     ump['V']=5;
    //     ump['X']=10;
    //     ump['L']=50;
    //     ump['C']=100;
    //     ump['D']=500;
    //     ump['M']=1000;
    //     int ans=0;
    // //    char prev= s[s.length()-1];
    // int  i=s.length()-2;
    // int n=s.length();
    // if(n==1) return ump[s[0]];
    //     while(i>=0){// failed at 3355 test case "MCDLXXVI"
    //         int temp=0;
    //         if(ump[s[i+1]]>ump[s[i]]){
    //             temp=ump[s[i+1]]-ump[s[i]];
    //         }
    //         else{
    //             temp=ump[s[i+1]]+ump[s[i]];
    //         }
    //         ans=ans+temp;
    //         if(i-2>=0){
    //             i=i-2;
    //         }
    //         else if(i==0){
    //             i--;
    //         }
    //         else{

    //             ans=ans+ump[s[i-1]];
    //             i=i-2;
    //         }
    //     }
    //     return ans;
    // }
    int romanToInt(string s) { 
    unordered_map<char,int> ump;
    ump['I']=1;
    ump['V']=5;
    ump['X']=10;
    ump['L']=50;
    ump['C']=100;
    ump['D']=500;
    ump['M']=1000;

    int ans = 0;
    int n = s.length();

    // Handle single-character case
    if (n == 1) return ump[s[0]];

    int i = n - 2;  // start from second last index

    while (i >= 0) {
        int curr = ump[s[i]];
        int next = ump[s[i + 1]];

        if (curr < next) {
            // subtractive case (like IV, IX, XL, etc.)
            ans += (next - curr);
            i -= 2; // skip both characters
        } else {
            // additive case — add the last one
            ans += next;
            i--; // move one step back
        }
    }

    // if first char (or remaining one) wasn’t processed
    if (i == -1) ans += ump[s[0]];

    return ans;
}

};
