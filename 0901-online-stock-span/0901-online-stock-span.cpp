class StockSpanner {
public:
    stack<int> st;
    vector<int> prices;
    StockSpanner() {}

    int next(int price) {
        prices.push_back(price);
        int n = prices.size() ;

            int span;
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && prices[st.top()] <= price) {
                st.pop();
            }
            if (st.empty()) {
                span = i + 1;
            } else {
                span = i - st.top();
            }
            st.push(i);
        }
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */