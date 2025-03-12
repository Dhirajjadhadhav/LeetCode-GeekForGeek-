int maximumCount(int* nums, int numsSize){

    int start = 0;
    int end = numsSize - 1;
    int mid,neg, pos;
    
    if(nums[0] > 0 || nums[numsSize -1] < 0)
        return numsSize;
    if(nums[0] == 0 && nums[numsSize -1] == 0)
        return 0;

    while(start<end)
    {
        mid = start + (end-start)/2;
        if(nums[mid]<0)
            start = mid+1;
        else
            end = mid;
    }
    neg = end;
    while(end<numsSize && nums[end] == 0)
    {
        end++;
    }
    pos = numsSize - end;
    return (pos>neg ? pos: neg);
}