// Convention:
// An algorithms question is posed in the following format:
//
// input:
// output:


// 1. Searching 
// input: an unsorted array A
//        a value x
// output: true if x in in A or false otherwise

// Brute-force solution:
//    x in A ? is equivalent to is there an index i such that A[i] == x ?
// Running time: sum_i=0, n-1(1) = n
// This is an OPTIMAL solution: no algorithms for this problem makes fewer than n-1 comparisons

Item linear_search(vector<Item> A, Item x)
{
	for (int i = 0; i < A.size(); ++i)
		if (A[i] == x)
			return true;
	return false;
}
	

// 2. Closest Pairs on the Plane
// input: n two-d points p[1..n] on the plane 
// output: a pair of such points with the smallest Euclidean distance between them
//         d(x1, y1, x2, y2) = sqrt((x1-x2)^2 + (y1-y2)^2)

// Running time is Theta(n^2)
// Not the best, which is Theta(nlog n), but acceptable

typedef pair(double, double) Point;

pair<Point, Point> closest_pair(vector<Point> p)
{
	assert(p.size() >= 2);

	Point b1 = p[0];
	Point b2 = p[1];

	for (int i = 0; i < p.size(); ++i)
		for (int j = i + 1; j < p.size(); ++j)
			if (dist(p[i], p[j]) < dist(b1, b2))
			{
				b1 = p[i];
				b2 = p[j];
			}

	return pair(b1, b2);
}

// 3.  String matching
// input: two strings:  text, pattern
// output: list all starting positions of pattern in text

// Running time: Theta(nm), n = size of text, m = size of pattern, unacceptable


vector<int> string_matching(string text, string pattern)
{
	vector<int> ans;

	for (int start = 0; start < text.size() - pattern.size(); ++start)
	{
		int i;
		for (i = 0; i < pattern.size(); ++i)
			if (text[start+i] != pattern[i])
				break;
		if (i == pattern.size())
			ans.push_back(start);
	}
	return ans;
}

// 4.  Median
// input:  array of n distinct integers
// output: return the median value of this array
//	   where the median is defined as follows:
//		if n is odd, it's the middle value
//		if n is even, it's the left middle value


Item median(vector<Item> v)
{
	for (auto e: v)
	{
		int greater_count(0);
		for (auto f: v)
			if (f > e)
				++greater_count;

		if (greater_count == v.size()/2)
			return e;
	}
}
		
// TRANFORM-CONQUER:  express given problem in terms of a known problem

// median can be found after sorting

Item median(vector<Item> v)
{
	merge_sort(v);
	return v[(v.size()-1)/2];
}



// least common multiple of 2 positive integers
// lcm(3, 2) = 6
// lcm(12, 9) = 36
// input: 2 positive integers a, b
// output: lcm(a, b)
// transform-conquer:  lcm(a,b) * gcd(a, b) = a*b

int lcm(int a, int b)
{
	return a*b/gcd(a, b);
}
		



			
		



