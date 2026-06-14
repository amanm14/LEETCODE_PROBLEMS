class Solution { //we can si ply use vector of 26 size and get solution without map which is taking log k extra time 
public://O(nlogk) as k is ony 26 letter so O(n) and sc O(k)==O(1) as k==26 letter
    int minSteps(string s, string t) {
        map<int,int>m1;
        map<int,int>m2;
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        int cnt=0;
        for(auto it:m1){
            if(!m2.count(it.first)){
                cnt+=m1[it.first];
            }
            else{
                if(m1[it.first]>m2[it.first])cnt+=m1[it.first]-m2[it.first];
            }
        }
        return cnt;
    }
};
