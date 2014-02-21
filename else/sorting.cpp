#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void printVector(vector<T>&v, int size)
{
    for(register int i=0; i<size; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

template <class T>
void insertionSorting(vector<T> &v, int size)
{
    for(register int i=1; i<size; i++)
    {
        T temp = v[i];
        int j;
        for(j=i; temp<v[j-1]; j--)
            v[j]=v[j-1];
        v[j] = temp;
    }
}

template <class T>
void shellSorting(vector<T> &v, int size)
{
    for(unsigned int increment=size/2; increment>0; increment/=2)
        for(unsigned int i=increment; i<size; i++)
        {
            T temp = v[i];
            unsigned int j;
            for(j=i; j>increment-1; j-=increment)
                if(temp<v[j-increment])
                    v[j]=v[j-increment];
                else
                    break;
            v[j] = temp;
        }
}

template <class T>
void mergeSort(vector<T> &v, int size)
{
    vector<T> temp(size, 0);
    m_sort(v, temp, 0, size - 1);
}


template <class T>
void m_sort(vector<T> &v, vector<T> &temp, int left, int right)
{
    T mid;
    if (right > left)
    {
        mid = (right + left) / 2;
        m_sort(v, temp, left, mid);
        m_sort(v, temp, mid+1, right);

        merge(v, temp, left, mid+1, right);
    }
}

template <class T>
void merge(vector<T> &v, vector<T> &temp, int left, int mid, int right)
{
    int i, left_end, num_elements, tmp_pos;

    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;

    while ((left <= left_end) && (mid <= right))
    {
        if (v[left] <= v[mid])
        {
            temp[tmp_pos] = v[left];
            tmp_pos = tmp_pos + 1;
            left = left +1;
        }
        else
        {
            temp[tmp_pos] = v[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }

    while (left <= left_end)
    {
        temp[tmp_pos] = v[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right)
    {
        temp[tmp_pos] = v[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }

    for (i=0; i <= num_elements; i++)
    {
        v[right] = temp[right];
        right = right - 1;
    }
}

template <class T>
void quicksort(vector<T> &v, int m, int n)
{
    int i,j,k;
	T key;
    if(m < n)
    {
		//k = choose_pivot(m,n);
		k = (m+n)/2;
        swap(v[m], v[k]);
        key = v[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (v[i] <= key))
                i++;
            while((j >= m) && (v[j] > key))
                j--;
            if( i < j)
                swap(v[i], v[j]);
        }
        // swap two elements
        swap(v[m], v[j]);
        // recursively sort the lesser list
        quicksort(v, m, j-1);
        quicksort(v,j+1,n);
    }
}

int main()
{
    int myints[] = {16,2,77,29,21,84,12,38,12};
    int size = sizeof(myints) / sizeof(int);
    vector<int> v (myints, myints + size);

//    insertionSorting<int>(v, size);
//    shellSorting<int>(v, size);
//    mergeSort<int>(v, size);
	quicksort<int>(v, 0, size-1);
    printVector<int>(v, size);

    return 0;
}
