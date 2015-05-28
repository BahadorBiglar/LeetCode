int rob(int* nums, int numsSize) {
    if (!numsSize)
        return 0;
    
    if (numsSize==1)
        return nums[0];
    
    int benefit[numsSize], max;
    benefit[0]=nums[0];
    benefit[1]=nums[1]>nums[0] ? nums[1]:nums[0];
    
    for (int house = 2; house < numsSize; house++){
        max = benefit[house-2] + nums[house]; 
        benefit[house] = benefit[house-1] > max ? benefit[house-1]:max;
    }
    return benefit[numsSize-1];
}