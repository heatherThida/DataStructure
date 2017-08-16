#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>

using namespace std;

typedef pair<double, double> point;

bool less_x(const point & a, const point & b)
{
  return (a.first < b.first);
}

bool less_y(const point & a, const point & b)
{
  return (a.second < b.second);
}

double dist(const point & a, const point & b)
{
  double dx = a.first - b.first;
  double dy = a.second - b.second;
  return sqrt(dx*dx + dy*dy);
}

// pre: V is sorted in x-coordinates
// post: returns minimum distance between 2 points in V AND
//       V is now sorted in y-coordinates

double closest_pair_2D(vector<point> &V)
{
  size_t n = V.size();
  if (n == 1)
    return INFINITY;
  if (n == 2)
    {
      sort(V.begin(), V.end(), less_y);
      return dist(V[0], V[1]);
    }
  // V is sorted in x-coordinates, so L and R are left and right halves
  vector<point>::const_iterator xi(V.begin());
  vector<point> L(xi, xi + n/2);
  vector<point> R(xi+n/2, xi+n);
  
  double delta = min(closest_pair_2D(L), closest_pair_2D(R));
  vector<point> Center;
  point median = V[n/2];

  merge(L.begin(), L.end(), R.begin(), R.end(), V.begin(), less_y);
  for (size_t i = 0; i < V.size(); ++i)
    if (abs(V[i].first - median.first) <= delta)
      Center.push_back(V[i]);

  size_t m = Center.size();
  for (size_t i = 0; i < m; ++i)
    for (size_t j = 1; j <= 7 && i+j < m; ++j)
      {
	double d = dist(Center[i], Center[i+j]);
	if (d < delta)
	  delta = d;
      }
  return delta;
}

double brute(const vector<point> V)
{
   size_t n = V.size();
   if (n == 1)
      return INFINITY;

   double delta = INFINITY;
   for (size_t i = 0; i < n - 1; ++i)
      for (size_t j = i+1; j < n; ++j)
      {
           double d = dist(V[i], V[j]);
           if (d < delta)
               delta = d;
      }
   return delta;
}
      
void print(const vector<point> & c)
{
  for (vector<point>::const_iterator i = c.begin(); i != c.end(); ++i)
    cout << "(" << (*i).first <<", " << (*i).second << ")" << endl;
  cout << endl;
}

int main()
{
  srand(time(0));
  size_t n;
  cout << "Enter n: ";
  cin >> n;

  vector<point> V;
  for (size_t i = 0; i < n; ++i)
	V.push_back(point(double(rand())/RAND_MAX, double(rand())/RAND_MAX));
     
  // sort in x-coordinates ONCE
  sort(V.begin(), V.end(), less_x);

  //  cout << "before:\n";  print(V);


  cout << closest_pair_2D(V) << endl;
  cout << brute(V) << endl;

   // cout << "after: \n";  print(V);

  





}
