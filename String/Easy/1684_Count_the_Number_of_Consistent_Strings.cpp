class Solution {
public://O(m-no. of words in vector) is tc and sc is O(1)
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int>check(26,0);
        for(int i=0;i<allowed.length();i++)
        {
            check[allowed[i]-'a']=1;
        }

        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            int tcnt=0;
            for(int j=0;j<temp.length();j++){
                if(check[temp[j]-'a']==0){
                    tcnt=0;
                    break;
                }
                else{
                    tcnt=1;
                }
            }
            ans+=tcnt;
            // cout<<ans<<endl;
        }
        return ans;
    }
};
