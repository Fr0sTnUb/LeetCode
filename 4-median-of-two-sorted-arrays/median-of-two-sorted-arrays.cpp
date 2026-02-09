class Solution {
public:
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
    const vector<int> *a = &A, *b = &B;
    if (a->size() > b->size()) swap(a, b);         
    int m = a->size(), n = b->size();
    int totalLeft = (m + n + 1) / 2;

    int lo = 0, hi = m;
    while (lo <= hi) {
        int i = (lo + hi) / 2;        
        int j = totalLeft - i;        

        int aLeft  = (i == 0) ? INT_MIN : (*a)[i - 1];
        int aRight = (i == m) ? INT_MAX : (*a)[i];
        int bLeft  = (j == 0) ? INT_MIN : (*b)[j - 1];
        int bRight = (j == n) ? INT_MAX : (*b)[j];

        if (aLeft <= bRight && bLeft <= aRight) {
            if ((m + n) % 2) return max(aLeft, bLeft);
            return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
        }
        if (aLeft > bRight) hi = i - 1; else lo = i + 1;
    }
    return 0.0;
}
};