bool backspaceCompare(char * s, char * t){

     int i,j;
        i = 0;
        j = 0;
        while(s[j]!='\0')
        {
            if(s[j] == '#')
            {
                if(i>0)
                --i;
            }
            else
                s[i++] = s[j];
            ++j;
        }
        s[i] = '\0';
        i = 0;
        j = 0;
        while(t[j]!='\0')
        {
            if(t[j] == '#')
            {
                if(i>0)
                --i;
            }
            else
                t[i++] = t[j];
            ++j;
        }
        t[i] = '\0';
        return !strcmp(s, t);
}