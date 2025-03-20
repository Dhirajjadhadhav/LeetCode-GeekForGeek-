class Solution {
    public:
        char findTheDifference(string s, string t) {
            char ch = 0;
            for(int i = 0; i<s.size(); ++i)
                ch ^= s[i];
            for(int i = 0; i<t.size(); ++i)
                ch ^= t[i];
            return ch;
        }
    };