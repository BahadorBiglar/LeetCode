void merge(int* nums1, int m, int* nums2, int n) {
    if (n==0)
        return;
    
    int p1, p2, p3, merged[m+n];
    p1=0;
    p2=0;
    p3=0;
    while ((p1<m) && (p2<n)){
        if (nums1[p1] < nums2[p2]){
            merged[p3]=nums1[p1];
            p1++;
        }
        else{
            merged[p3]=nums2[p2];
            p2++;
        }
        p3++;
    }
    while (p1<m){
        merged[p3]=nums1[p1];
        p1++;
        p3++;
    }
    while (p2<n){
        merged[p3]=nums2[p2];
        p2++;
        p3++;
    }
    for (p3=0; p3<m+n; p3++)
        nums1[p3]=merged[p3];
}