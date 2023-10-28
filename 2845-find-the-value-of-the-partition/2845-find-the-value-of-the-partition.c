int cmp(const void* a, const void* b)
{
    return  *(int*)a-*(int*)b;
}
int findValueOfPartition(int* nums, int numsSize){

    int min = INT_MAX;
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int i = 0; i<numsSize-1; ++i)
        min  = fmin(min, nums[i+1]-nums[i]);
    return min;    
}