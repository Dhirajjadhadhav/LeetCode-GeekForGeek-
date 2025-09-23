int compareVersion(char* version1, char* version2) {
    int i = 0, j = 0;
        
        while (i < strlen(version1) || j < strlen(version2)) {
            int i2 = 1, j2 = 1;
            char vs1[501];
            char vs2[501];
            bzero(vs1, 500);
            bzero(vs2, 500);
            vs1[0] = '0';
            vs2[0] = '0';
            vs1[500] = '\0';
            vs2[500] = '\0';
            
            while (i < strlen(version1) && version1[i] != '.') {
                vs1[i2++] += version1[i++];
            }
            while (j < strlen(version2) && version2[j] != '.') {
                vs2[j2++] += version2[j++];
            }
            int vi1 = atoi(vs1), vi2 = atoi(vs2);
            if (vi1 < vi2) {
                return -1;
            }
            else if (vi1 > vi2) {
                return 1;
            }
            ++i; ++j;
        }
        return 0;
}