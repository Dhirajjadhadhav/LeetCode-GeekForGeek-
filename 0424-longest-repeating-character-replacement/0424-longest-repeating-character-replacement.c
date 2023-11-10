int characterReplacement(char* s, int k) {
    
    int n =strlen(s);
    int i,j,max;
    int  hash[26] = {0};

    int ans = -1;

     i = 0;
     j = 0;
     max = 0;

     while(j<n)
     {
        hash[s[j]-'A']++;
        max = fmax(max, hash[s[j]-'A']);
        if((j-i+1)-max>k)
        {
            hash[s[i]-'A']--;
            ++i;
        }
        ans = fmax(ans, j-i+1);
        ++j;
     }
     return ans;
}