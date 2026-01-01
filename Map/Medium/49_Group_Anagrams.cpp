class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>st;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++)//tc is O(n*klogk) and sc is O(n*k) n is hash map k is vector ehich store ech string vector
        {//there is faster way of doing it in the only O(n*k) without using the sorting method foir only small alphabet using string key(26,'0')?
            string z=strs[i];
            string k=z;
            sort(z.begin(),z.end());
           mp[z].push_back(k);
        }
        for(auto i:mp){
            st.push_back(i.second);
        }
        return st;
        // for(int i=0;i<strs.size();i++)//tc is O(n2klogk) very expensive
        // {
        //     string temp=strs[i];
        //     vector<string>ans;
        //     ans.push_back(temp);
        //     sort(temp.begin(),temp.end());
        //     // int s=
        //     for(int j=i+1;j<strs.size();j++){
        //         string z=strs[j];
        //         string k=z;
        //         sort(z.begin(),z.end());
        //         // cout<<"hello"<<j<<strs[j]<<z<<endl;
        //         if(temp==z){
        //             // cout<<"hello"<<j<<endl;
        //             ans.push_back(k);
        //             strs.erase(strs.begin()+j);//tc is O(N erase is costly
        //             --j;
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        //     st.push_back(ans);
        //     ans.clear();
        // }
        // return st;
    }
};
