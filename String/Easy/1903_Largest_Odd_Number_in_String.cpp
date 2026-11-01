class Solution {
public:// o(n) is tc and sc is O(1) leaving aux space a.length for output
    string largestOddNumber(string num) {
        int ans=0,t=0;
        int idx=-1;
        for(int i=num.length()-1;i>=0;i--)
        {
            t=num[i]-'0';
            if(t%2!=0)
            {
                idx=i;
                break;
            }
        }
        if(idx==-1) return "";
        int i=0;
        string a="";
        while(i<=idx)
        {
            t=num[i]-'0';
            a.push_back(num[i]); 
            i++;
        }
        
        return a;
    }
};
