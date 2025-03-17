/*
    Time complexity -: O(N)
    space comxity -: O(N)
*/

bool divideArray(int* nums, int numsSize) {
    int hash[501] = {0};

    for(int i = 0; i<numsSize; ++i)
        hash[nums[i]]++;

    for(int i = 1; i<=500; ++i)
        if(hash[i]&1)return false;
    return true;
}