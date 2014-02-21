class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0, j = 0;
        for(i=0; i<n; )
        {
            if(A[i] == elem)
            {
                i++;
            }
            else
            {
                A[j] = A[i];
                j++, i++;
            }
        }
        return j;
    }
};
