class Solution {
    public int countSegments(String s) {//0(n) is tc and sc is 0(1)
        if (s.isEmpty()) {
            return 0;
        }

        int cnt = 0;
        boolean m = false;

        for (char ch : s.toCharArray()) {
            if (ch != ' ') {
                m = true;
                continue;
            }

            if (ch == ' ' && m) {
                cnt++;
                m = false;
            }
        }

        if (m) {
            cnt++;
        }

        return cnt;
    }
}
