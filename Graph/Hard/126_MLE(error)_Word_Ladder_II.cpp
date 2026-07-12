class Solution {//MLE <- error but solution is right
public://Time complexity is impossibel to predict it will depend example to exmaple
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>>q;
        vector<string>usedOnlevel;
        vector<vector<string>>ans;

        
        unordered_set<string>st(wordList.begin(),wordList.end());

        q.push({beginWord});
        usedOnlevel.push_back(beginWord);
        st.erase(beginWord);
        int level=0;
        bool found=false;
        while(!q.empty())
        {
            vector<string>vic=q.front();
            q.pop();
            if(vic.size()>level){
                if(found==true) break;
                level++;
                for(auto it:usedOnlevel){
                    st.erase(it);
                }
                usedOnlevel.clear();
            }

            

            string word=vic.back();//as last word using which we need to traverse must be at last of vic string vector

            if(word==endWord){
                found=true;
                if(ans.size()==0){
                    ans.push_back(vic);
                }
                else if(ans[0].size()==vic.size()){
                    ans.push_back(vic);
                }
            }

            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.count(word)>0){
                        usedOnlevel.push_back(word);
                        vic.push_back(word);
                        q.push(vic);
                        vic.pop_back();
                    }
                    
                }
                word[i]=original;
            }

        }
        return ans;
    }
};
