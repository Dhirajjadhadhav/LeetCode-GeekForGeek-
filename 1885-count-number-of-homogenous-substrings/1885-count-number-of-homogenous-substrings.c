#define MOD 1000000007
int countHomogenous(char * s){

    int total = 1,cnt = 1;
    char tmp = s[0];
    int i = 1;
    while(s[i]!='\0')
    {
        if(tmp == s[i])
            ++cnt;
        else
        {
            tmp = s[i];
            cnt = 1;
        }
        total  = (total+cnt)%MOD;
        ++i;
    }

    return total;
}