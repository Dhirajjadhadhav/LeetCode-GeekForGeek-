class Solution {
public:
    vector<int> decimalRepresentation(int n) {

        vector<int>res;
        int i = 0;
        while(n > 0)
        {
           if(n%10 != 0)
           {
               int val = n%10 * pow(10, i);
               res.push_back(val);
           }
            n/=10;
            ++i;    
        }
        reverse(res.begin(), res.end());
        return res;
    }
};