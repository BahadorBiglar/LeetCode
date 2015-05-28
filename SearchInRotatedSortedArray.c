int findBreakPoint(int* nums, int numsSize){
    int lb=0, ub=numsSize-1;
    int mid;
    
    while (lb<ub){
        if (lb==ub-1){
            if (nums[lb] > nums[ub])
                return lb;
            else
                return ub;
        }
            
        mid = (lb+ub)>>1;
        if (nums[mid] > nums[ub]){
            lb=mid;
        }
        else if (nums[mid] < nums[lb]){
            ub=mid;
        }
        else return ub;
    }
    return lb;
}

int binarySearch(int* nums, int numsSize, int lb, int ub, int target){
    int mid;
    if (ub>numsSize-1)
        ub = numsSize-1;
    while (lb<=ub){
        mid = (lb+ub)>>1;
        if (target == nums[mid])
            return mid;
        if (target > nums[mid]){
            lb=mid+1;
        }
        else{
            ub=mid-1;
        }
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    if (numsSize==0)
        return -1;
    
    int pos = findBreakPoint(nums, numsSize);
    if (target >= nums[0])
        return binarySearch(nums, numsSize, 0, pos, target);
    if (target <= nums[numsSize-1])
        return binarySearch(nums, numsSize, pos+1, numsSize-1, target);
    return -1;
}
