int Solution::majorityElement(const vector<int> &A) {
    int num = NULL;
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (count == 0 || A[i] == num) {
            count++;
            num = A[i];
        } else {
            count--;
        }
    }
    int ans = 0;
    for (int x : A) {
        if (x == num) {
            ans++;
        }
    }
    if (ans > A.size()/2) {
        return num;
    }
    return -1;
}
