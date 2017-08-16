#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

template <class T>
void merge(vector<T> &v, int lo, int mid, int hi)
{
	int n = hi - lo + 1;

	vector<T> temp(n);
	size_t i(lo), j(mid+1);
	for (size_t k = 0; k < n; ++k)
	{
		if (i > mid)
			temp[k] = v[j++];
		else if (j > hi)
			temp[k] = v[i++];
		else if (v[j] < v[i])
			temp[k] = v[j++];
		else
			temp[k] = v[i++];
	}
	copy(temp.begin(), temp.begin()+n, v.begin()+lo);
}

template <class T>
void merge_sort(vector<T> &v, int lo, int hi)
{
	if (lo < hi)
	{
		int mid = lo + (hi -lo)/2;
		merge_sort(v, lo, mid);
		merge_sort(v, mid+1, hi);
		merge(v, lo, mid, hi);
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
		merge_sort(v, 0, v.size()-1);
		assert(is_sorted(v.begin(), v.end()));
	}
	return 0;
}

