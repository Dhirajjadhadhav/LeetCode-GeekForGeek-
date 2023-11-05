int getWinner(int* arr, int arrSize, int k) {
    
    int i, j;
    int max = 0;
    int* prefix = (int*)malloc(arrSize * sizeof(int));
    max = arr[0];
    
    if(k>=arrSize)
    {
        for(i = 0; i<arrSize; ++i)
        {
        max = fmax(max, arr[i]);
        }
        return max;
    }
     
    i = 1;
    int cnt = 0;
    max = arr[0];
    while(i<arrSize)
    {
        if(max == fmax(max, arr[i]))
        {
            cnt++;
           
        }
        else
        {
            max = arr[i];
            cnt = 1;
    
        }
        if(cnt == k)
            return max;
        ++i;
    }
    return max;
}