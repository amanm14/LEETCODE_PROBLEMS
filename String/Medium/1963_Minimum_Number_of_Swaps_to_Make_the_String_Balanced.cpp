class Solution {
public://O(N) and O(1) tc and sc
    int minSwaps(string s) {
    int balance = 0;
    int maxImbalance = 0;

    for (char c : s) {
        if (c == '[') balance++;
        else balance--;

        if (balance < 0)
            maxImbalance = max(maxImbalance, -balance);
    }

    return (maxImbalance + 1) / 2;
}


};
