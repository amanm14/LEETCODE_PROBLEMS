class Solution {
public://O(n) is tc and sc is O(1)
    vector<int> scoreValidator(vector<string>& events) {
         int s=0;
         int c=0;
         for(int i=0;i<events.size();i++)
         {
            if(c==10||s==10) break;
            if(events[i]=="0") continue;
            else if(events[i]=="1") s+=1;
            else if(events[i]=="2") s+=2;
            else if(events[i]=="3") s+=3;
            else if(events[i]=="4") s+=4;
            else if(events[i]=="6") s+=6;
            else if(events[i]=="W") c++;
            else if(events[i]=="WD") s+=1;
            else s+=1;
         }
         return {s,c};
    }
};
