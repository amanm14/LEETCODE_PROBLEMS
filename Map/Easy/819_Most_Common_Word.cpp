class Solution {
public://ascii 65 to 90 and 97 to 122 tc is O(nlog n) and sc is O(n)
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int>mp;
        
        string str="";
        for(int i=0;i<paragraph.length();i++){
            char z=tolower(paragraph[i]);
            int y=z;
            if(i+1==paragraph.length()){
                if(y>96&&y<123)str.push_back(z);
                 mp[str]++;
            }
            else if(y>96&&y<123){
                str.push_back(z);
            }
            else{
                mp[str]++;
                 str="";
            }
        }
        for(int i=0;i<banned.size();i++){
            mp[banned[i]]=-1;
        }
        
        int ma=INT_MIN;
        string ans="";
        for(auto i:mp){
            cout<<i.first<<" v  "<<i.second<<endl;
            int k=i.second;
            int s=i.first.length();
            if(ma<k&&s>0){
                ma=max(ma,k);
                ans=i.first;
            }
        }
        return ans;
    }
};
