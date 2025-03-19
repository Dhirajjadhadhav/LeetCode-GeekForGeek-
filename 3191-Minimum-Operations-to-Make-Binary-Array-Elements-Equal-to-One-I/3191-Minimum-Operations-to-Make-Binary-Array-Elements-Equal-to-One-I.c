int minOperations(int* nums, int numsSize) {
    int cnt = 0;   
    for(int i = 0; i<numsSize; ++i){
        if(nums[i] == 0){
            if(i+2>=numsSize)return -1;
            ++cnt;
            nums[i] = !nums[i];
            nums[i+1] = !nums[i+1];
            nums[i+2] = !nums[i+2];
        }
    }
    return cnt;
}