class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i <= s.length(); i++) {

            if (isalnum(int(s[i]))) {
                ans += s[i];
            }
            if (s[i] == ' ' && isalnum(int(s[i + 1]))) {
                ans += " ";
            }
        }
        if (!ans.empty() && ans[0] == ' ')
            ans.erase(0, 1);
        s = ans;

        int start = 0;
        for (int i = 0; i <= s.length(); i++) {
            if (s[i] == ' ' || i == s.length()) {

                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
    return s;
    }
};