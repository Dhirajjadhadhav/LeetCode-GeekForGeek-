class Solution {
public:
    string sortVowels(string s) {
        string ovels;

        for(int i = 0; i!=s.size(); ++i)
        {
            if(s[i] == 'A' || s[i] == 'a' || 
                s[i]=='E' ||s[i] == 'e' ||
                s[i] == 'I' || s[i] == 'i' || 
                s[i] == 'O' || s[i] == 'o' || 
                s[i] == 'U' || s[i] == 'u')
                    ovels+= s[i];
        }

        std::sort(ovels.begin(), ovels.end());
       int j = 0;
        for(int i = 0; i!=s.size(); ++i)
        {
            if(s[i] == 'A' || s[i] == 'a' || 
                s[i]=='E' ||s[i] == 'e' ||
                s[i] == 'I' || s[i] == 'i' || 
                s[i] == 'O' || s[i] == 'o' || 
                s[i] == 'U' || s[i] == 'u')
                    s[i] = ovels[j++];
            
        }
        return s;
    }
};