class Solution {
public://O(n) is tc and sc is O(1)
    bool isBalanced(string num) {
        int x=0,y=0;
        for(int i=0;i<num.length();i++)
        {
            if(i%2==0)
            {
                int t=num[i]-'0';
                x+=t;
            }
            else 
            {

                int t=num[i]-'0';
                y+=t;
            }
        }
        if(x==y) return true;
        return false;
    }
};
