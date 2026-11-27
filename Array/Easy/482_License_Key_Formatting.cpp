class Solution {
public://0(n) is tc and sc is 0(1)
    string licenseKeyFormatting(string s, int k) {
        string temp = "";

    //remove dashes and uppercase krdo
    for(char c : s)
    {
        if(c != '-')
        {
            temp += toupper(c);
        }
    }

    string ans = "";
    int count = 0;
    //reverse tracking
    for(int i=temp.size()-1; i>=0; i--)
    {
        ans += temp[i];
        count++;

        if(count == k && i!=0)
        {
            ans += "-";
            count = 0;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
