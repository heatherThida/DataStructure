#include <iostream>
#include <algorithm>

using namespace std;

template <class Item>
void merge(Item A[], int left, int mid, int right)
{
	int n = right - left + 1;
	Item temp[n];
	int i(left), j(mid+1), k;

	for (k = 0; k < n; ++k)
	{
		if (i > mid || (j <= right && A[j] < A[i]))
			temp[k] = A[j++];
		else
			temp[k] = A[i++];
	}
	copy(temp, temp+n, A+left);

}

template <class Item>
void merge_sort(Item A[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid+1, right);
		merge(A, left, mid, right);
	}
}


void sort()
{
  //int A[] = {3, 4, 5, 10, 9, 1, 7, 2, 6, 8};


  //int A[] = {30, 22, 31, 19, 41, 2, 43, 26, 15, 5, 16, 10, 14, 23, 7, 25, 47, 17, 35, 44, 4, 49, 12, 27, 48, 34, 38, 45, 28, 50, 13, 1, 32, 24, 33, 37, 20, 46, 42, 9, 3, 39, 11, 21, 29, 18, 40, 36, 8, 6};

  int A[] = {97, 98, 91, 1, 27, 23, 30, 68, 82, 78, 17, 8, 31, 59, 89, 99, 69, 79, 21, 22, 77, 58, 41, 15, 60, 85, 80, 90, 48, 6, 51, 65, 54, 13, 93, 2, 64, 96, 24, 100, 14, 47, 39, 87, 71, 20, 26, 84, 9, 25, 35, 42, 86, 16, 33, 12, 55, 7, 32, 46, 73, 38, 4, 50, 76, 61, 95, 3, 81, 10, 28, 34, 94, 75, 67, 11, 83, 52, 40, 88, 49, 44, 63, 72, 43, 66, 62, 45, 37, 74, 70, 56, 29, 5, 19, 18, 92, 36, 57, 53};

  int n = sizeof(A)/sizeof (int);
  merge_sort(A, 0, n-1);
}

int main()
{
  for (int k = 0; k < 1000000; ++k)
      sort();
}  

