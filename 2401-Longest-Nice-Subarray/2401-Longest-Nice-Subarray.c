#define MAX(X, Y) ((X)>(Y)) ? (X) : (Y)

int longestNiceSubarray(int* nums, int numsSize) {
    int bitMask = 0;
    
    int i = 0, j = 0;  
    int res = 1; 
    while(j<numsSize){
        while((bitMask&nums[j]) != 0){
            bitMask ^= nums[i];
            ++i;
        }
        bitMask |= nums[j];
      
        res = MAX(res, j-i+1);
        ++j;
    }
    return res;
}