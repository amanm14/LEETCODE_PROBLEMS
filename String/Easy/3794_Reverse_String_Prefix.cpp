class Solution {
public://O(k) is tc and O(1) is sc
    string reversePrefix(string s, int k) {
        int i=0;
        int j=k-1;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};
