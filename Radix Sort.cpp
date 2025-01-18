#include <iostream>  
using namespace std;  
int getMax(int a[], int n) 
{  
   int max = a[0];  
   for(int i = 1; i < n; i++) 
   {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;   
}
void countingSort(int a[], int n, int place) 
{  
  int output[n];  
  int count[10] = {0};     
  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;   
  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];    
  for (int i = n - 1; i >= 0; i--) 
  {  
    output[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  for (int i = 0; i < n; i++)  
    a[i] = output[i];  
}    
void radixsort(int a[], int n) 
{  
  int max = getMax(a, n);  
  for (int place = 1; max / place > 0; place *= 10)  
    countingSort(a, n, place);  
}    
void printArray(int a[], int n) 
{  
  for (int i = 0; i < n; ++i)   
    cout << a[i] << " ";  
  cout << endl;
}  
int main() 
{  
  int n;  
  cout << "Enter the number of elements in the array: ";  
  cin >> n;  
  int a[n];  
  cout << "Enter the elements of the array:\n";  
  for (int i = 0; i < n; i++) 
  {  
      cin >> a[i];  
  }  
  cout << "\nBefore sorting, array elements are:\n";  
  printArray(a, n);  
  radixsort(a, n);  
  cout << "\nAfter applying Radix sort, the array elements are:\n";  
  printArray(a, n);  
  return 0;    
}
