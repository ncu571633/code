/*
   We're given a sorted array of integers: [-3, -1, 0, 1, 2]. We want to generate a sorted array of their squares: [0, 1, 1, 4, 9]
*/

#include "main.hpp"
vector<int> generateArray(vector<int> v)
{
    vector<int> ret;
    int n = v.size();
    if(!n)
        return ret;

    // find min number
    int i = 0, j = n-1;
    while(i<j) {
        int k = (i+j) / 2;
        if(v[i]*v[i] > v[j]*v[j]) {
            i = k;
        } else {
            j = k;
        }
    }
    j = i+1;
    while(i>=0 && j<n) {
        if(v[i]*v[i] < v[j]*v[j]) {
            ret.push_back(v[i]*v[i]);
            i--;
        } else {
            ret.push_back(v[j]*v[j]);
            j++;
        }
    }
    if(i>=0) {
        for(int k=i; k>=0; k--)
            ret.push_back(v[k]*v[k]);
    }
    if(j<=n) {
        for(int k=j; k<n; k++)
            ret.push_back(v[k]*v[k]);
    }
    return ret;
}

int main()
{
    //int t[] = {-3, -1, 0, 1, 2};
    //int t[] = {-3, -1, 0, 1, 1, 2, 2, 3, 4, 5};
    int t[] = {1};
    vector<int> v = generateArray(vector<int>(t, t+sizeof(t)/sizeof(int)));
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
}
