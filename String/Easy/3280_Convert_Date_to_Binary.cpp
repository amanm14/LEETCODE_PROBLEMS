
class Solution {
public://O(n) is tc and O(1) is sc
    string convert(int t) {
        if (t == 0) return "0";

        string ans = "";

        while (t > 0) {
            ans.push_back((t % 2) + '0');
            t /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string convertDateToBinary(string date) {
        string ans = "";
        int num = 0;

        for (int i = 0; i < date.length(); i++) {
            num = 0;

            while (i < date.length() && date[i] != '-') {
                num = num * 10 + (date[i] - '0');
                i++;
            }

            ans += convert(num);

            if (i < date.length())
                ans.push_back('-');
        }

        return ans;
    }
};
