int findKthLargest(int* nums, int numsSize, int k) {
    if (numsSize == 0)
        return -1;
    if (numsSize == 1)
        return nums[0];
    
    int item = nums[numsSize-1];
    int greaters = 0, equals = 0;
    for (int pos = 0; pos < numsSize-1; pos++){
        if (item < nums[pos])
            greaters++;
        else if (item == nums[pos])
            equals++;
    }
    
    if (greaters > (k - 1))
        return (findKthLargest(nums, numsSize-1, k));
    if (greaters == (k - 1))
        return item;
    if (greaters + equals >= (k - 1))
        return item;
    return (findKthLargest(nums, numsSize-1, k-1));
}