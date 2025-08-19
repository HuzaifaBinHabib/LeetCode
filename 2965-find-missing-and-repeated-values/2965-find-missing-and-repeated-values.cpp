class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        unordered_set<int> m;

        vector<int> ans;
        int a;
        int acualsum = 0;
        int expectsum = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                acualsum += arr[i][j];
                if (m.find(arr[i][j]) != m.end()) {
                    a = arr[i][j];
                    ans.push_back(a);
                }
                m.insert(arr[i][j]);
            }
        }
        expectsum = (n * n) * (n * n + 1) / 2;
        ans.push_back(expectsum - acualsum + a);

        return ans;
    }
};