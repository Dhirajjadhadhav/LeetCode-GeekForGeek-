class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        for(int i = 0; i<s.size(); ++i){
            
            if(st.size()>1 && s[i] == 'c'){
                char prev = st.top(); 
                st.pop();
                char pprev = st.top(); 
                st.pop();
                if(prev == 'b' && pprev == 'a')
                    continue;
                st.push(pprev);
                st.push(prev);
            }
            st.push(s[i]);
        }
        return st.empty();
    }
};