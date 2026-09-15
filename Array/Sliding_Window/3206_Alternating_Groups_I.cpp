class Solution {
public://O(n) is tc and sc is O(1)
    int numberOfAlternatingGroups(vector<int>& colors) {
        int x,y,z,cnt=0;
        if(colors.size()<3) return 0;
        // x=colors[0];
        // y=colors[1];
        // z=colors[2];
        for(int i=0;i<colors.size();i++)
        {
           if(i>=2)
           {
            // cout<<"h1"<<endl;
            x=colors[i-2];
            y=colors[i-1];
            z=colors[i];
            if(x!=y&&x==z)
            {
                cnt++;
                cout<<"h"<<endl;
            }
            if(i==colors.size()-1)
            {
                if(colors[i-1]!=colors[i]&&colors[i-1]==colors[0]) cnt++;
                if(colors[i]!=colors[0]&&colors[i]==colors[1]) cnt++;
                cout<<"hello"<<endl;
            }
            
           }
            
            
        }
        return cnt;
        // int s=0;
        // for(int i=0;i<colors.size();i++)
        // {
        //     while(i-s==3)
        //     {
        //         x=
        //         y=
        //         z=
        //     }
        //     if()
        //         {
        //             cnt++;
        //         }
        // }
    }
};
