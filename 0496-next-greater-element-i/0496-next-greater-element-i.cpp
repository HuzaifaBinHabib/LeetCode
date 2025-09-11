class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        int n2 = nums2.size();
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() > 0 && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            auto it = m.find(nums1[i]);
            if (it != m.end()) {
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};