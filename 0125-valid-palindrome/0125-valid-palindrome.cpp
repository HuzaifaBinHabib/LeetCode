class Solution {
public:
    bool isPalindrome(string a) {
        int lp = 0;
        int rp = a.length() - 1;
        while (lp <= rp) {
            if (!isalnum(a[lp])) {
                lp++;
                continue;
            }
            if (!isalnum(a[rp])) {
                rp--;
                continue;
            }
            if (tolower(a[lp]) != tolower(a[rp])) {

                return false;
            }
            lp++;
            rp--;
        }
    return true;
    }
};