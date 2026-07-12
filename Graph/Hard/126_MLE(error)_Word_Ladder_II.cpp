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

//BFS + parent map + DFS reconstruction approach

class Solution {
public://Above one is accepted and interview oriented question we can skip this one
    unordered_map<string, vector<string>> parent;
    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string word, string &beginWord) {

        path.push_back(word);

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        else {
            for (auto &par : parent[word]) {
                dfs(par, beginWord);
            }
        }

        path.pop_back();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_set<string> currLevel, nextLevel;

        currLevel.insert(beginWord);

        bool found = false;

        while (!currLevel.empty() && !found) {

            // Remove current level words from dictionary
            for (auto &w : currLevel)
                dict.erase(w);

            for (auto &word : currLevel) {

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {

                    char original = temp[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        temp[i] = ch;

                        if (!dict.count(temp))
                            continue;

                        nextLevel.insert(temp);

                        parent[temp].push_back(word);

                        if (temp == endWord)
                            found = true;
                    }

                    temp[i] = original;
                }
            }

            currLevel = nextLevel;
            nextLevel.clear();
        }

        if (!found)
            return {};

        dfs(endWord, beginWord);

        return ans;
    }
};
