int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <=1)
        return numsSize;
    int pos=0, diff=1;
    while ((pos+diff)<=(numsSize-1)){
        if (nums[pos]==nums[pos+diff]){
            diff++;
        }
        else{
            nums[pos+1]=nums[pos+diff];
            pos++;
        }
    }
    return pos+1;
}