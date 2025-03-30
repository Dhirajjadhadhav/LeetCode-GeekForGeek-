class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[26] = {0};

        for(int i = 0; i<s.size(); ++i)
        {
            hash[s[i]-'a'] = i;
        }
        vector<int>res;

        int i = 0;
        while(i<s.size()){
            int last = hash[s[i]-'a'];
            int j = 0;
            while(j< s.size() && j<=last){
                last = max(last, hash[s[j]-'a']);
                ++j;
            }
           res.push_back(j-i);
           i = j;           
        }
        return res;
    }
};