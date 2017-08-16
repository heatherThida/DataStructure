/*
 HW 4 (2/17 due)
 CSCI 163 Prof. N. Tran
 Thida Aung
 
 1.   Write a function merge3(A, lo, mid1, mid2, hi) that combines three sorted subarrays
 A[lo..mid1], A[mid1+1..mid2], A[mid2+1..hi] into a sorted array and puts the result back into A[lo..hi].
 */

#include <iostream>
#include <vector>

using namespace std;

void merge3(vector<int> &v, int lo, int mid1, int mid2, int hi)
{
    vector<int> temp;
    
    int ii = lo; // Index in first section.
    int jj = mid1; // Index in second section.
    int kk = mid2; // Index in third section.
    
    while (ii < mid1 || jj < mid2 || kk < hi) {
        int ii_elem = -1;
        int jj_elem = -1;
        int kk_elem = -1;
        if (ii < mid1) {
            ii_elem = v[ii];
        }
        if (jj < mid2) {
            jj_elem = v[jj];
        }
        if (kk < hi) {
            kk_elem = v[kk];
        }
        if ((ii_elem <= jj_elem || jj >= mid2) && (ii_elem <= kk_elem || kk >= hi) && ii < mid1) {
            temp.push_back(ii_elem);
            ii++;
        }
        if ((jj_elem <= kk_elem || kk >= hi) && (jj_elem <= ii_elem || ii >= mid1) && jj < mid2) {
            temp.push_back(jj_elem);
            jj++;
        }
        if ((kk_elem <= jj_elem || jj >= mid2) && (kk_elem <= ii_elem || ii >= mid1) && kk < hi) {
            temp.push_back(kk_elem);
            kk++;
        }
    }
    
    for (int ii = 0; ii < temp.size(); ii++) {
        v[ii + lo] = temp[ii];
    }
}
//  asymptotic running time for this is O(hi-lo)

/*
 2.   Write a function merge_sort_3(A, lo, hi) that sorts an array by dividing it into approximately3 equal thirds,
 recursively sorting each third, and combining the sorted subarrays into a sorted array.
 */

void merge_sort_3(vector<int> &v, int lo, int hi)
{
    if (lo < hi - 1) {
        int size = hi - lo;
        int mid1 = size/3 + lo;
        int mid2 = size/3 * 2 + lo;
        // Section of array is too small to divide into 3, then just move both of the pointers by 1 so we will
        // sort one section, and just leave the other section as sorted.
        if (mid1 == lo) {
            mid1++;
        }
        if (mid2 < mid1) {
            mid2++;
        }
        
        merge_sort_3(v, lo, mid1);
        merge_sort_3(v, mid1, mid2);
        merge_sort_3(v, mid2, hi);
        merge3(v, lo, mid1, mid2, hi);
    }
}

int main(int argc, char *argv[])
{
    int arr[] = {10, 1, 3, -1, 2, 4, 5, 6, 3};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    
    merge_sort_3(v, 0, 9);
    
    for (int ii = 0; ii < v.size(); ii++) {
        cout << v[ii] << endl;
    }
    cout << endl;
    
    return 0;
}

// asymptotic running time for this is O(n lg n) with log base 3



