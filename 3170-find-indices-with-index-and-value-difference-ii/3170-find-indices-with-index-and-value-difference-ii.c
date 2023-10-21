/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findIndices(int* nums, int numsSize, int indexDifference, int valueDifference, int* returnSize) {

    int i, j;
    int min_j, max_j;
    int* ans = (int*)malloc(2*sizeof(int));
    ans[0] = -1;
    ans[1] = -1;
    *returnSize = 2;
    min_j = 0;
    max_j = 0;

    for(i = indexDifference, j= 0; i<numsSize; ++i,++j)
    {
        min_j = nums[min_j]<nums[j] ? min_j : j;
        max_j = nums[max_j]>nums[j] ? max_j : j;
        if(abs(nums[i]-nums[min_j])>=valueDifference)
        {
            ans[0] = min_j;
            ans[1] = i;
            break;
        }
        if(abs(nums[i]-nums[max_j])>=valueDifference)
        {
            ans[0] = max_j;
            ans[1] = i;
            break;
        }
    }
    return ans;
}