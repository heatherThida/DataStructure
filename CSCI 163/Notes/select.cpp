// selection:
// input: unsorted array A[lo..hi]
//        1 <= k <= n = hi - lo + 1

// output: k^th smallest element in A

// brute-force:
//    remove minimum k times, and return the last removed element
//    run-time: O(nk)
//    When k = Theta(n),  this is O(n^2) algorithm

// transform:
// sort and return the k^th element from the left A[lo + k - 1]
// run-time: O(nlg n)

// divide-conquer: leads to a linear (but complicated) algorithm

// first attempt
// run-time ?
// C(n) = number of array element comparisons (pivot > A[j])

// C(1) = 0
// C(n) = n-1 + C(s),   s = size of partition containing k^th smallest element

// worst-case: s = n -1
// C(n) = n-1 + C(n-1)
// C(n) = n(n-1)/2     QUADRATIC!!!!!!!!!!!

// on average:
// C(n) is linear

template <class Item>
Item quick_select(vector<Item> v, int lo, int hi, int k)
{
	int n = hi - lo + 1;

	// base case
	if (n == 1)
		return v[lo];

	int p = partition(v, lo, hi);
	int prank = p - lo + 1;    // rank of pivot

	if (k == prank)           // looking for the pivot
		return v[k];

	if (k < prank)
		return quick_select(v, lo, k - 1, k);

	else
		return quick_select(v, k + 1, hi, k - prank);
}


template <class Item>
Item linear_select(vector<Item> v, int lo, int hi, int k)
{
	int n = hi - lo + 1;

	if (n < 5)
	{
		insertion_sort(v, lo, hi);
		return v[lo + k - 1];

	}

	int g = n/5;  // number of groups
	Item M[g];    // array of medians

	for (int i = 0; i < g; ++i)
	{
		insertion_sort(v, lo + 5*i, lo + 5*i + 4);
		M[i] = v[lo + 5*i + 2];   // median of (sorted) group i
	}

	// med is the median of the medians, guaranteed to be in the middle third
	Item med = linear_select(M, 0, g-1, g/2);

	// place the median of medians at the rightmost position
	for (int i = lo; i <= hi; ++i)
	{
		if (v[i] == med)
		{
			swap(v[hi], v[i];
			break;
		}
	}

	int p = partition(v, lo, hi);
	int prank = p - lo + 1;

	if (k == prank)
		return v[p];
	if (k < prank)
		return linear_select(v, lo, p-1, k);
	else
		return linear_select(v, p+1, hi, prank - k);
}
	





}
