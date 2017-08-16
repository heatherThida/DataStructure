#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

template <class T>
void selection_sort(vector<T> & v)
{
	for (int n = v.size(); n > 1; --n)
	{
		int max(0);
		for (int j = 1; j < n; ++j)
			if (v[j] > v[max])
				max = j;

		swap(v[max], v[n-1]);
	}
}

template <class T>
void insertion_sort(vector<T> & v)
{
   	for (int i = 1; i < v.size(); ++i)
		for (int j = i; j > 0 && v[j] < v[j-1]; --j)
			swap(v[j], v[j-1]);
}

int main()
{
	srand(time(NULL));

	int N(1000);

	for (int i = 1; i <= N; ++i)
	{
		vector<int> v(N);
		for (int j = 1; j <= N; ++j)
			v.push_back(j);

		random_shuffle(v.begin(), v.end());
		//selection_sort(v);
		insertion_sort(v);
		assert(is_sorted(v.begin(), v.end()));
	}
	return 0;
}

