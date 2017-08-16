// decrease-conquer: given a problem of size n, find solution to a reduced problem
//                    of size n-1, and then use it to find solution to original problem

// 1. MAX of an array of size n
// input: an subarray A[lo..hi]
// output: the largest value in this subarray

// count number of comparisons betwen array elements temp > v[hi]
// C(1) = 0
// C(n) = C(n-1) + 1
// C(n) = n-1, n >= 0

Item max(vector<Item> v, int lo, int hi)
{
	if (lo == hi)
		return v[lo];

	Item temp = max(v, lo, hi-1);
	return (temp > v[hi]) ? temp: v[hi];
}

// Count number of comparisons of array elements
// C(1) = 0
// C(n) = (n-1) + C(n-1), n > 1.
// C(n) = sum_{j=1, n-1} j  = n(n-1)/2

void selection_sort(vector<Item> & v, int lo, int hi)
{
	if (lo >= hi)
		return;

	swap(v[hi], v[indexMax(v, lo, hi)]);
	selection_sort(v, lo, hi-1);
}

// C(1) = 0
// C(n) = C(n-1) + sum_{p = lo+1, hi} 1
//      = C(n-1) + (n-1)
// C(n) = n(n-1)/2
	
void insertion_sort(vector<Item> & v, int lo, int hi)
{
	if (lo >= hi)
		return;
	insertion_sort(v, lo, hi-1);
	for (int p = hi; p > lo && v[p] < v[p-1]; --p)
		swap(v[p], v[p-1]);
}

// M(1) = 0
// M(n) = M(n-1) + 1
// M(n) = n-1

double horner(vector<double> c, int lo, int hi, double v)
{
        if (lo == hi)
		return c[lo];

	return horner(c, lo+1, hi, v) * v + c[lo];
}

// C(n) = C(n) + constant
// C(n) = Theta(n)

pair<point, point> maxblocksuffix(vector<v>, int lo, int hi)
{
	if (lo > hi)
		return (-1, -1), (-1, -1)  // empty blocks

	(mb, ms) = maxblocksuffix(v, lo, hi-1);
	if (ms + v[hi] > mb)
		return (ms + v[hi], ms + v[hi]);
	else
		return (mb, (ms+v[hi] > 0 ? ms+v[hi] : 0);
}
