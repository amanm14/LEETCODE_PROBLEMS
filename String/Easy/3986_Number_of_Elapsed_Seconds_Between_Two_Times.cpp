class Solution {
public://O(nis tc ans sc is O(1)    
int secondsBetweenTimes(string startTime, string endTime) {
        int ans=0,tt=3600;
        for(int i=0;i<startTime.length();i++)
        {
            cout<<"i "<<i<<endl;
            int x=0;
            x=startTime[i];
            x=x-'0';
            
            int t=startTime[i+1];
            t=t-'0';
            // cout<<"t"<<t<<endl;
            x=x*10+t; //x*=10+t ==x=x*(x+t) thats why it is not equa; to this
            // cout<<"x "<<x<<endl;

            int y=0;
            y=endTime[i]-'0';
            // cout<<"y "<<y<<endl;
            int u=endTime[i+1]-'0';
            // cout<<"u"<<u<<endl;
            y=y*10+u;
            // cout<<"y "<<y<<endl;

            ans=ans+(y-x)*tt;
            tt=tt/60;
            i++;
            i++;
            // cout<<ans<<" "<<x<<" "<<y<<endl;
        }
        return ans;
    }
};
