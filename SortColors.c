void sortColors(int* nums, int numsSize) {
    int colors[3]={0};
    for (int i = 0; i<numsSize; i++)
        colors[nums[i]]++;
    
    int currColor = 0;
    for (int i = 0; i<numsSize; i++){
        while (colors[currColor]==0)
            currColor++;
        nums[i] = currColor;
        colors[currColor]--;
    }
    
}