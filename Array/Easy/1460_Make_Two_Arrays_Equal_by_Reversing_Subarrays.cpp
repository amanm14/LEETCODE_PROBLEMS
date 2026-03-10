class Solution {
public://0(n) is tc and 0(1) is sc
    bool canBeEqual(vector<int>& targetArray, vector<int>& currentArray) {
        vector<int> elementCounts(1001, 0);
        int uniqueCount = 0;
        
        for (int i = 0; i < targetArray.size(); i++) {
            if (elementCounts[targetArray[i]]++ == 0) uniqueCount++;
            if (elementCounts[currentArray[i]]-- == 1) uniqueCount--;
        }
        
        return uniqueCount == 0;
    }
}; //it can be solve using map
