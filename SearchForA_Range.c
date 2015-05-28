int* searchRange(int* nums, int numsSize, int target, int* returnSize) {

    int starting=numsSize;
    int ending=-1;
    int lb,ub,mid;
    int *result;
    *returnSize=2;
    
    lb=0;
    ub=numsSize-1;
    
    while (lb<=ub){
        mid = (lb+ub) / 2;
        if (nums[mid]==target){
            starting = mid;
            ub=mid-1;
        }
        else if (nums[mid]>target){
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }
    }
    
    lb=0;
    ub=numsSize-1;
    
    while (lb<=ub){
        mid = (lb+ub) / 2;
        if (nums[mid]==target){
            ending = mid;
            lb=mid+1;
        }
        else if (nums[mid]>target){
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }
    }
    
    result[0] = starting < numsSize ? starting:-1;
    result[1] = ending;
    return result;
}    
