class Solution {

//     Time	O(N × L)	traverse each word and character
//    Space	O(N × L)	store valid words in result

public:
    vector<string> findWords(vector<string>& words) {
        map<char,int>mp;
        vector<string>ans;
        mp['q']=1;
        mp['w']=1;
        mp['e']=1;
        mp['r']=1;
        mp['t']=1;
        mp['y']=1;
        mp['u']=1;
        mp['i']=1;
        mp['o']=1;
        mp['p']=1;

        mp['a']=2;
        mp['s']=2;
        mp['d']=2;
        mp['f']=2;
        mp['g']=2;
        mp['h']=2;
        mp['j']=2;
        mp['k']=2;
