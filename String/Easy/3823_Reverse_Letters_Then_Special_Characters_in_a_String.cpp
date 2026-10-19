class Solution {
public://O(n+n) is tc and sc is O(1)
    string reverseByType(string s) {
        // if(s.length()==2) {
        //     swap(s[0],s[1]);
        //     return s;
        // }
        int i=0;

        int j=s.length()-1;
        while(i<j)
        {
            cout<<s[i]<<endl;
            if(s[i]-'a'>=0&&s[i]-'a'<=25&&s[j]-'a'>=0&&s[j]-'a'<=25)
            {
                swap(s[i],s[j]);
                // cout<<s<<endl;
                i++;
                j--;
            }
            else if(s[i]-'a'<0||s[i]-'a'>25)
            {
                i++;
                // cout<<s<<endl;
            }
            else{
                j--;
                // cout<<s<<endl;
            }
        }
        i=0;
        j=s.length()-1;
        while(i<j)
        {
             if((s[i]-'a'<0||s[i]-'a'>25)&&(s[j]-'a'<0||s[j]-'a'>25))
            {
                swap(s[i],s[j]);
                // cout<<s<<endl;
                i++;
                j--;
            }
            else if(s[i]-'a'>=0&&s[i]-'a'<=25)
            {
                i++;
                // cout<<s<<endl;
            }
            else{
                j--;
                // cout<<s<<endl;
            }
        }
        return s;
    }
};
