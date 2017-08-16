#include <limits>
#include <iostream>
#include <cmath>

// Thida : Limited coin change problem 

using namespace std;

int d[]= {1,5,7}; //domination coins
int s[] = {4,3,2};  //how many of each d are there
int k = 3;
int A[n];
int cc(int n, int d[],int s[]){
 
    for (int i=0; i<=n ; ++i){
       A[i] = 1000000;
A[0] = 0;

       //go through all possible denomination
       for (int j = 1; j <= k ; ++j){
          if(i -d[j] >= 0){
            A[i] = min(A[i], 1 + A[i-d[j]]);  
           }
       }
    }
   return A[n];
} 


int main()
{
   cc(15, d, s); 
   cout << "Smallest set of coins is: " << A[n] << endl;
   return 0;
}    
