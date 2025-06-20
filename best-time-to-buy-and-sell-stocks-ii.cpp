int Solution::maxProfit(const vector<int> &A) {
    int currPrice = 0;
    int num = 0;
    int profit = 0;
    for (int i = 0; i < A.size(); i++) {
        if (i==A.size()-1 && num==1) {
            num--;
            profit += (A[i]-currPrice);
        } else if (A[i+1] > A[i] && num==0) {
            num++;
            currPrice = A[i];
        } else if (A[i+1] < A[i] && num==1) {
            num--;
            profit += (A[i]-currPrice);
        }
    }
    return max(0, profit);
}
