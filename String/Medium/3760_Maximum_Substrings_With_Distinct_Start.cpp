class Solution {
public://O(n) is tc and O(1) is sc
    int maxDistinct(string s) {
        int arr[26]={0},cnt=0;
        for(int i=0;i<s.length();i++)
        {
            int x=s[i]-'a';
            if(arr[x]==0){
                cnt++;
                arr[x]=1;
            } 
        }
        return cnt;
    }
};
