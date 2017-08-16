#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

// pre: lo < hi
template <class T>
int partition(vector<T> & v, int lo, int hi)
{
	int i(lo), j(hi+1);
	T pivot(v[lo]);

	while (true)
	{
		while (v[++i] < pivot && i < hi)
			;
		while (pivot < v[--j] && j > lo)
			;

		if (i >= j)
			break;
		swap(v[i], v[j]);
	}
	swap(v[lo], v[j]);
	return j;
}

template <class T>
void quick_sort(vector<T> &v, int lo, int hi)
{
	if (lo < hi)
	{
		int k = partition(v, lo, hi);
		quick_sort(v, lo, k-1);
		quick_sort(v, k+1, hi);
	}
}

int main()
{
	srand(time(NULL));

	int N(10000);

	for (int i = 1; i <= N; ++i)
	{
		vector<int> v(N);
		for (int j = 1; j <= N; ++j)
			v.push_back(j);

		random_shuffle(v.begin(), v.end());
		quick_sort(v, 0, v.size()-1);
		assert(is_sorted(v.begin(), v.end()));
	}
	return 0;
}

