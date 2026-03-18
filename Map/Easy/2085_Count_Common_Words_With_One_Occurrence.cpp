class Solution {
public://0(nlogn) is tc and 0(n) is sc
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> mp;
        int n1 = words1.size();
        int n2 = words2.size();
        for (int i = 0; i < n1; i++) {
            if (!mp.contains(words1[i]))
                mp[words1[i]]++;
            else
                mp[words1[i]] += 2;
        }
        for (int i = 0; i < n2; i++) {
            if (mp[words2[i]] == 1)
                mp[words2[i]]++;
            else if (mp[words2[i]] >= 2)
                mp[words2[i]] += 2;
        }
        // words appearing exactly once in each of the vectors will have value =
        // 2
        n1 = 0; // don't create extra variable. Use alreafy created one to store
                // answer
        for (auto& it : mp) {
            if (it.second == 2)
                n1++;
        }

        return n1;
    }
};
