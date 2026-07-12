class Solution {
public:// tc is -> [word.length()*26*N(wordList.length()-->nuber of times queue will execute)*log(N)<-set insertion and erase ] and SC is O(N)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(word==endWord){
                return lvl;
            }
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,lvl+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
