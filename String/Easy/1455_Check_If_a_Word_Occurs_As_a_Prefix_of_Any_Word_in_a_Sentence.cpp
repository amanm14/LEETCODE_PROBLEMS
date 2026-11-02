class Solution {
public://O(N) is tc and sc is O(1)
    int isPrefixOfWord(string sentence, string searchWord) {
        int t=1;
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' '){
                t++;
                continue;
            }
            int z=0;
            while(sentence[i]==searchWord[z]&&z<searchWord.length())
            {
                i++;
                z++;

            }
            if(z==searchWord.length()) return t;
            if(sentence[i]==' '){ t++; continue;}
            while(i+1<sentence.length()&&(sentence[i+1]!=' ')) i++;
            
        }
        return -1;
    }
};
