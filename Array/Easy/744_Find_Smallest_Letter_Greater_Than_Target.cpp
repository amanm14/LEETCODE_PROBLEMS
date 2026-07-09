class Solution {
public://O(n) is tc and sc is O(n)
    char nextGreatestLetter(vector<char>& letters, char t) {
    if((letters[letters.size()-1]-'a')<(t-'a')) return letters[0];
    // cout<<"1 "<<endl;
    if((letters[letters.size()-1]-'a')>(t-'a')&&letters[0]-'a'>(t-'a')) return letters[0];

        for(int i=0;i<letters.size();i++)
        {
            // cout<<"2 "<<endl;
            if(letters[i]-'a'>t-'a') return letters[i];
        }
        // cout<<"3 "<<endl;
        return letters[0];
    }
};
