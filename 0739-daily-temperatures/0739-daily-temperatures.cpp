class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n =temp.size();
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){ 
        while(st.size()>0 && temp[st.top()] < temp[i]){
          int idx =st.top();
          st.pop();
          ans[idx]= i-idx;
        }
        st.push(i);
        }
        return ans;
    }
};