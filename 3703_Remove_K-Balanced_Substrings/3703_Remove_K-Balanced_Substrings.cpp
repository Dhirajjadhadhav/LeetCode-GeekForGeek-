class Solution {
public:
    string removeSubstring(string s, int k) {
        string res;

        for(char c : s)
        {
            res += c;
            int sz  = res.size();
            if(sz >= 2*k)
            {
                bool valid  = true;
                for(int i = 0; i<k; ++i)
                {
                    if(res[sz-2*k+i] != '(')
                    {
                        valid = false;
                        break;
                    }
                    if(res[sz-k+i] != ')')
                    {
                        valid = false;
                        break;
                    }
                }
                if(valid)
                    res.resize(sz - 2*k);
            }
           
        }
         return res;
    }
};