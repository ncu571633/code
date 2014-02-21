class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(needle==NULL)
           return haystack;
        int l1 = strlen(haystack);
        int l2 = strlen(needle);
        for(int i=0; i<l1-l2+1; i++)
        {
            int j=0, k=i;
            for(j=0; j<l2; j++, k++)
            {
                if(haystack[k] != needle[j])
                    break;
            }
            if(j==l2)
                return haystack+i;
        }
        return NULL;
    }
};
