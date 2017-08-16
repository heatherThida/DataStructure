#include <iostream>
using namespace std;


template <class Item>
int partition(Item A[], int lo, int hi)
{
	int i(lo), j;
	Item pivot(A[hi]);
	
	for (j = lo; j < hi; ++j)
	{
		if (pivot > A[j])
			swap(A[i++], A[j]);
	}
	swap(A[i], A[hi]);
	return i;
}

template <class Item>
void quick_sort(Item A[], int lo, int hi)
{
	if (lo < hi)
	{
		// divide
		int k = partition(A, lo, hi);
		// conquer
		quick_sort(A, lo, k-1);
		quick_sort(A, k+1, hi);
		// no combine step!
	}
}
