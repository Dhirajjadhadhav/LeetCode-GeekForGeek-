int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize) {

    int max = 0;
    int i;
    for(i = 0; i<leftSize; ++i)
        max = fmax(max, left[i]);
    for(i = 0; i<rightSize; ++i)
        max = fmax(max, n-right[i]);
    
    return max;   
}