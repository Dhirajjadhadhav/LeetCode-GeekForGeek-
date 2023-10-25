/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void merge(int* arr, int p, int q, int r)
{
    int N1 = q-p+1;
    int N2 = r-q;
    int i,j, k;

    int* a1 = (int*)malloc(N1*sizeof(int));
    int* a2 = (int*)malloc(N2*sizeof(int));

    for(int i = 0; i<N1; ++i)   
        a1[i] = arr[p+i];
    for(int i = 0; i<N2; ++i)
        a2[i] = arr[q+i+1];

    i = j = k = 0;
    while(1)
    {
        if(a1[i]<=a2[j])
        {
            arr[p+k] = a1[i];
            ++i;
            ++k;
            if(i == N1)
            {
                while(j<N2)
                {
                    arr[p+k] = a2[j];
                    ++j;
                    ++k;
                }
                break;
            }
        }
        else
        {
            arr[p+k] = a2[j];
            ++k;
            ++j;
            if(j == N2){
                while(i<N1)
                {
                    arr[p+k] = a1[i];
                    ++k;
                    ++i;
                }
                break;
            }
        }
    }
    free(a1);
    free(a2);
}
void merge_sort(int* arr, int p, int r)
{
    int q;
    if(p<r)
    {
        int q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q,r);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    merge_sort(nums, 0, numsSize-1);
    return nums;
}