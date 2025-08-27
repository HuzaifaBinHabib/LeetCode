class Solution {
public:
    bool ispalen(string part) {
        int lp = 0;
        int rp = part.length() - 1;
        while (lp < rp) {
            if (part[lp] != part[rp]) {
                return false;
            }
            lp++;
            rp--;
        }
        return true;
    }
    void rap(string s, vector<string> partition, vector<vector<string>>& ans) {
        int n = s.length();

        if (n == 0) {
            ans.push_back({partition});
            return;
        }

        for (int i = 0; i < n; i++) {
            string part = s.substr(0, i + 1);
            if (ispalen(part)) {
                partition.push_back(part);
                rap(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        rap(s, partition, ans);
        return ans;
    }
};