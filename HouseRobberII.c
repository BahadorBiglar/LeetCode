int rob(int* nums, int numsSize) {
    if (!numsSize)
        return 0;
    
    if (numsSize==1)
        return nums[0];
    
    int max;
    int benefitWithFirstHouse[numsSize];
    int benefitWithoutFirstHouse[numsSize];
    
    benefitWithFirstHouse[0]=nums[0];
    benefitWithoutFirstHouse[0]=0;
    
    benefitWithFirstHouse[1]=nums[1]>nums[0] ? nums[1]:nums[0];
    benefitWithoutFirstHouse[1]=nums[1];
    
    for (int house = 2; house < numsSize; house++){
            if (house < (numsSize-1)){
                max = benefitWithFirstHouse[house-2] + nums[house];
                benefitWithFirstHouse[house] = benefitWithFirstHouse[house-1] > max ? benefitWithFirstHouse[house-1]:max;
            }
            else{
                benefitWithFirstHouse[house] = benefitWithFirstHouse[house-1];
            }
            
            max = benefitWithoutFirstHouse[house-2] + nums[house];
            benefitWithoutFirstHouse[house] = benefitWithoutFirstHouse[house-1] > max ? benefitWithoutFirstHouse[house-1]:max;
    }
    max = benefitWithFirstHouse[numsSize-1];
    if (max < benefitWithoutFirstHouse[numsSize-1])
        max = benefitWithoutFirstHouse[numsSize-1];
    return max;
}