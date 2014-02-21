class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int t[3];
        t[0]=t[1]=t[2]=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')  t[0]++;
            if(s[i]==')')  t[0]--;
            if(s[i]=='{')  t[1]++;
            if(s[i]=='}')  t[1]--;
            if(s[i]=='[')  t[2]++;
            if(s[i]==']')  t[2]--;
        }
        for(int i=0; i<3; i++)
            if(t[i])
               return false;
        
        stack <char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
               st.push(s[i]);
               continue;
            }
            if(st.empty())
                return false;
            char c = st.top();
            st.pop();
            if((s[i]==')'&&c=='(') || (s[i]=='}'&&c=='{') || (s[i]==']'&&c=='['))
            {
                continue;
            }
            return false;
        }
        return true;
    }
};
