class disJointSet
{
    public:
    vector<int>par,rank,size;
    disJointSet(int n)
    {
        par.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<n;i++) par[i]=i;
    }
    int findPar(int n)
    {
        if(n==par[n]) return n;
        else return par[n]=findPar(par[n]);
    }
    void unionBySize(int u,int v)
    {
        int ult_u=findPar(u);
        int ult_v=findPar(v);
        if(ult_u==ult_v) return;
        if(size[ult_u]<size[ult_v])
        {
            par[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else
        {
             par[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }

    }
};
class Solution {
public:
//N: The number of accounts.
// K: The total number of emails across all accounts (sum of all account lengths).
// L: The average length of an email string.


// TC--> o(L*K*Log(L)) and sc --> O(K*L)

    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n=details.size();
        unordered_map<string,int>mailToNode;
        disJointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<details[i].size();j++)
            {
                string mail=details[i][j];
                if(mailToNode.find(mail)==mailToNode.end())
                {
                    mailToNode[mail]=i;
                }
                else
                {
                    ds.unionBySize(i,mailToNode[mail]);
                }
            }
        }
        vector<vector<string>>mergeMail(n);
        for(auto it:mailToNode)
        {
            string mail=it.first;
            int node=ds.findPar(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(mergeMail[i].size()==0) continue;
            vector<string>temp;
            temp.push_back(details[i][0]);
            sort(mergeMail[i].begin(),mergeMail[i].end());
            for(auto it:mergeMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
