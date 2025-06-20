int Solution::maxProfit(const vector<int> &A) {
    int max_profit = 0;
    int price = INT_MAX;
    
    for (int i = 0; i < A.size(); i++) {
        price = min(price, A[i]);
        max_profit = max(max_profit, A[i]-price);
    }
    return max_profit;
}
