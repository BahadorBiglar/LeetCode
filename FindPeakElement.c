int findPeakElement(int num[], int n) {
    for (int pos = 0 ; pos < n ; pos++){
        int prev = (pos == 0)   ? num[pos]:num[pos-1];
        int next = (pos == n-1) ? num[pos]:num[pos+1];
        if (num[pos] >= prev && num[pos] >= next)
            return pos;
    }
    return -1;
}