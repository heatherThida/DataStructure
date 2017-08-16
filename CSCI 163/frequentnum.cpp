
#include<iostream>
#include<algorithm>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

//maxrepeat or frequent item in subarray (if tie, pick any)


//template <class Item>
int maxrepeat(int* arr, int n, int k){
  for (int i = 0; i <n ; i++){
    arr[arr[i]%k] += k;
   // cout << arr[i] <<endl;
  }
  int max = arr[0], result = 0;
  for (int i = 1; i< n; i++){
    if(arr[i] > max){
        max = arr[i];
        result = i;
        //cout << "\nresult: " << result << endl;
    }
  }

  return result;
}


//countEach

int freqitem(int* arr, int size){
    
    int freq[100];
    int i, j;
    int max2 = 0;
    for (i=0; i< size; i++)
    {
        int count2 = 1;
        for( j=i+1; j< size; j++)
        {
            if(arr[i]==arr[j])
            {
                count2++;
                freq[j] = 0;
                //cout<< "freq[i] is: " << freq[i] << endl;
            }
        }
        
        if(freq[i]!=0)
        {
            freq[i] = count2;
            //cout<< "hello" << endl;
            if(freq[j] > freq[i]){
               max2 = freq[j];
               //cout << "max2 inside if : " << max2 << endl;
            }
            else {
               max2 = freq[i];
               //cout << "max2 inside if : " << max2 << endl;
            }
         }
    
    }//end of countEach
    return max2;
    //cout <<"The most frequent item in this unsorted array is : " << max2 << endl;
    
}


//Brute Force
int freqitem2(int *arr, int lo, int hi) {
    int max_freq = 0;
    int max_item = 0;
    for (int ii = lo; ii < hi; ++ii) {
        int count = 0;
        for (int jj = ii; jj < hi; ++jj) {
            if(arr[ii] == arr[jj]){
                count++;
            }
        }
        if(count > max_freq ){
            max_freq = count;
            max_item = arr[ii];
        }
        
    }
    return max_item;
} // O(n^2)

//using map (can I use for Transform conquer)

int unordered_map_freq(int *arr, int size) {
    unordered_map<int, int> freq_map;
    for (int ii = 0; ii < size; ++ii) {
        if (freq_map.find(arr[ii]) == freq_map.end()) {
            freq_map[arr[ii]] = 0;
        }
        freq_map[arr[ii]]++;
    }
    int max_freq = 0;
    int max_elem = 0;
    for (unordered_map<int, int>::iterator it = freq_map.begin();
         it != freq_map.end(); ++it) {
        if (it->second > max_freq) {
            max_freq = it->second;
            max_elem = it->first;
        }
    }
    return max_elem;
}// O (n)

int freq_of_elem(int *arr, int lo, int hi, int elem) {
    int count = 0;
    for (int ii = lo; ii < hi; ++ii) {
        if (arr[ii] == elem) {
            count++;
        }
    }
    return count;
}

int decrease_by_one_freq_helper(int *arr, int lo, int hi, int max_freq,
                                int max_elem) {
    if (lo == hi) {
        // The frequency of this element is 1, so if the max_freq is 0,
        // then return the element, otherwise return max_elem.
        if (max_freq < 1) {
            return arr[lo];
        } else {
            return max_elem;
        }
    } else {
        int cur_elem_freq = freq_of_elem(arr, lo, hi, arr[lo]);
        if (cur_elem_freq > max_freq) {
            return decrease_by_one_freq_helper(arr, lo + 1, hi, cur_elem_freq,
                                               arr[lo]);
        } else {
            return decrease_by_one_freq_helper(arr, lo + 1, hi, max_freq,
                                               max_elem);
        }
    }
} // O(n^2)


int decrease_by_one_freq(int *arr, int lo, int hi) {
    return decrease_by_one_freq_helper(arr, lo, hi, 0, 0);
}

int sorted_arr_freq(int *arr, int lo, int hi) {
    int max_count = 0;
    int max_item = 0;
    int current_count = 1;
    for (int ii = lo; ii < hi - 1; ++ii) {
        if (arr[ii] == arr[ii + 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
                max_item = arr[ii];
            }
            current_count = 1;
        }
    }
    current_count++;
    if (current_count > max_count) {
        max_count = current_count;
        max_item = arr[hi - 1];
    }
    return max_item;
}


/*
void merge(int *arr, int lo, int mid, int hi)
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
 
void merge_sort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = lo + (hi -lo)/2;
        merge_sort(v, lo, mid);
        merge_sort(v, mid+1, hi);
        merge(v, lo, mid, hi);
    }
}
*/
 
void sort(int *arr, int size){
    //bubble sort
    int temp;
    for(int i = 0; i < size; i++)
    {
        for(int j = i; j < size; j++)
        {
            if(arr[j] < arr[i])
            {
                //swap them
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
//template <class Item>
int main()
{
    int arr[] = {2, 5, 5, 3, 5, 3, 4, 1, 7};
    //int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;
    //cout << "Before" << endl;
    //for (int i=0; i< 10; ++i){
    //    cout << arr[i] << endl;
    //}
    //cout << "The maximum repeating number is " << maxrepeat(arr, 10, 8) << endl;
    
    //cout << "After" << endl;
   // for (int j=0; j< 10; ++j){
     //   cout << arr[j] << endl;
    //}
    //cout << "The max from freqitem is " << freqitem(arr, 10) << "\n" << endl;
    
    cout << "The max from freqitem2 is " << freqitem2(arr, 0, 9) << "\n" << endl;
    //cout << "Max unordered map is " << unordered_map_freq(arr, 10) << "\n" << endl;
    cout << "Max decrease  by one is " << decrease_by_one_freq(arr, 0, 9) << "\n" << endl;
    
    sort(arr,10);
    cout << "Max sorted is " << sorted_arr_freq(arr, 0, 9) << "\n" << endl;

    
    return 0;
}



