class Solution {
public:
    int compress(vector<char>& a) {
        vector<char> ans;
        int count = 1;
        for (int i = 0; i < a.size(); i++) {
            if (i + 1 < a.size() && a[i] == a[i + 1]) {
                count++;
            } else {
                ans.push_back(a[i]);                 
                if (count > 1) {
                    string s = to_string(count); 
                    for (char val : s){ 
                        ans.push_back(val);
                        }
                }
                count = 1; 
            }
        }
        a = ans; 
        return a.size();
    }
};
