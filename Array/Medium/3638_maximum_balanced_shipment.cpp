
class Solution {
public:0(n) is tc and 0(1) sc
int maxBalancedShipments(vector<int>& weight) {
        int res = 0, maxa = 0;
        for (int a : weight) {
            maxa = max(maxa, a);
            if (a < maxa) {
                res++;
                maxa = 0;
            }
        }
        return res;
    }
};
