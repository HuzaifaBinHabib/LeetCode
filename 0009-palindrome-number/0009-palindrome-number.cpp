class Solution {
public:
    bool isPalindrome(int x) {
        string s1 = to_string(x);
        int lp = 0;
        int rp = s1.length() - 1;

        while (lp < rp) {
            if (s1[lp] == s1[rp]) {
                lp++;
                rp--;
            } else {
                if (lp == rp) {
                    return true;
                }
                return false;
            }
        }
        return -1;
    }
};