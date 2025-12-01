class Solution {
public: //O(Nlogn+nk(k is time to find in map)) wheere SC is O(1) as we have only 26 chars
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        int count=0;
        sort(chars.begin(),chars.end());

        for(int i=0;i<chars.length();i++)
        {
            mp[chars[i]]++;
            cout<<chars[i]<<endl;
        }
        bool flag=true;
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            flag=true;
            int idx=temp.length();
            for(int j=0;j<temp.length();j++)
            {
                if(mp[temp[j]]<1)
                {
                    flag=false;
                    // cout<<"hello";
                    idx=j;
                    break;
                }
                else{
                    mp[temp[j]]--;
                }
            }
            // cout<<"count"<<count<<endl;
            if(flag==true)
            {
                count=count+temp.length();
                
            }
            for(int j=0;j<idx;j++)
            {
                if(mp.find(temp[j])!=mp.end()) mp[temp[j]]++;
            }
        }
        return count;
    }
};
