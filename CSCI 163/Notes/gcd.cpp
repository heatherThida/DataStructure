// input: 2 nonnegative integers a, b
// output: their greatest common divisor, gcd(a, b)
// Examples:
//  gcd(6, 15) = 3
//  gcd(49, 14) = 7
//  gcd(n, 0) =  n,  n > 0

#include <iostream>
#include <algorithm>

using namespace std;

unsigned gcd1(unsigned a, unsigned b)
{
	unsigned d;
	for (d = min(a, b); d > 0 && (a % d != 0 || b % d  != 0); --d)
		;

	return d;
}

unsigned gcd2(unsigned a, unsigned b)
{
	while (b > 0)
	{
		unsigned t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	unsigned a, b;
	cout << "Enter a, b: ";
	cin >> a >> b;

	cout << "gcd2 = " << gcd2(a, b) << endl;

	return 0;
}


