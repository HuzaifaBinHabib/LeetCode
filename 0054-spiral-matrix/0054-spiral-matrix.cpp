class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int srows = 0;
        int erows = m.size() - 1;

        int scols = 0;
        int ecols = m[0].size() - 1;

        vector<int> ans;

        while (srows <= erows && scols <= ecols) {

            for (int i = scols; i <= ecols; i++) {
                ans.push_back(m[srows][i]);
            }
            for (int i = srows + 1; i <= erows - 1; i++) {
                ans.push_back(m[i][ecols]);
            }
            for (int i = ecols; i >= scols; i--) {
                if (erows == srows) {
                    break;
                }
                ans.push_back(m[erows][i]);
            }
            for (int i = erows - 1; i >= srows + 1; i--) {
                if (ecols == scols) {
                    break;
                }
                ans.push_back(m[i][scols]);
            }
            scols++;
            ecols--;
            srows++;
            erows--;
        }

        return ans;
    }
};