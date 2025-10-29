class Solution {
public:
    int maxArea(vector<int>& ht) {
        int width = 0;
        int height = INT_MAX;
        int lp = 0;
        int rp = ht.size() - 1;
        int ans = INT_MIN;

        while (lp < rp) {
            width = rp - lp;
            height = min(ht[lp], ht[rp]);
            int area = width * height;
            ans = max(area, ans);
            if (ht[lp] < ht[rp]) {
                lp++;
            } else {
                rp--;
            }
        }

        return ans;
    }
};