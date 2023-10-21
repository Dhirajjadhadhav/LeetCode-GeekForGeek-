char* shortestBeautifulSubstring(char* s, int k){

    int i, j, cnt;
    int start = 0,end = INT_MAX/10;
    char* ans = NULL;
    i = 0;
    j = 0;
    cnt = 0;
    while(s[j]!='\0' || cnt>=k)
    {

        if(cnt<k)
        {   
            if(s[j] == '1')
                ++cnt;
            ++j;
        }
       
        if(cnt == k)
        {
            if(end-start == j-i && (strncmp(s+start, s+i, j-i)>0))
            {
                start = i;
                end = j;
            }
            
            if(end-start>j-i)
            {
                start = i;
                end = j;
            }
            if(s[i] == '1')
            {
                --cnt;
            } 
            ++i;
        }
    }
   if(end == INT_MAX/10)
        return "\0";
    int len = end-start;
    ans = (char*)malloc((len+1)*sizeof(char));
    strncpy(ans, s+start, len);
    ans[len] = '\0';
    return ans;

}