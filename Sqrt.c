int mySqrt(int x) {
    if (x==0)
        return 0;
    if (x<=3)
        return 1;

    int UB, mid, LatestLB = 1;
    int LB = 1;
    UB = (x/2) + 1;
    if (x > 46340)
        UB = 46340;
    while (LB <= UB){
        mid = (UB + LB) / 2;
        int mid2 = mid*mid;
        if (mid2<x){
            LatestLB = mid;
            LB = mid + 1;
        }
        if (mid2>x)
            UB = mid - 1;
        if (mid2==x)
            return mid;
    }
    return LatestLB;
}