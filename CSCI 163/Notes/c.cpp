#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N = 100000;

	int M[N] = {0};

	for (int i = 2; i < N; ++i)
	{
		M[i] = M[i/2] + M[i-i/2] + i-1;
		cout << i << ": " << M[i] << " " << M[i]/((double) i*log(i)) << endl;
	}
}
