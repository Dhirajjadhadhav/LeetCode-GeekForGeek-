#define MAX(X,Y) ((X>Y) ? (X):(Y));

int integerBreak(int n){
    int* dp = (int*)malloc((n+1)* sizeof(int));
    if(n<3)
        return 1;
    if(n == 3)
        return 2;
    dp[0]= 0;
    dp[1] = 1;
    dp[2] = 2;
    
    int max = INT_MIN;
    int i,j;
    int half;
    int val;
    int a,b;

    for(i = 3; i<=n; ++i){
        half = i/2;
        for(j = 1; j<=half; ++j){
           a = MAX(dp[j], j)
           b= MAX(dp[i-j], i-j);
           val = a*b;
           max = MAX(max, val);
        } 
        dp[i] = max;
    }
    int ans = dp[n];
    free(dp);
    dp = NULL;
    return (ans);

}