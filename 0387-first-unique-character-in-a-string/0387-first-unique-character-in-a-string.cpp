class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        unordered_map<char, int> m;
        int freq = 1;

        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }
            m[s[i]]++;
            while (q.size() > 0 && m[s[q.front()]] > 1) {
                q.pop();
            }
        }
        if (q.empty()) {
            return -1;
        }
        return q.front();
    }
};