#include <iostream>
#include <climits>
using namespace std;
void countingSort(int arr[], int n, int minVal, int maxVal) 
{
    int range = maxVal - minVal + 1;  
    int *count = new int[range];  
    int *output = new int[n];  
    for (int i = 0; i < range; i++) 
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) 
    {
        count[arr[i] - minVal]++;  
    }
    for (int i = 1; i < range; i++) 
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) 
    {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;  
    }
    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }
    delete[] count;
    delete[] output;
}
int main() 
{
    int n, minVal, maxVal;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the minimum value of the elements: ";
    cin >> minVal;
    cout << "Enter the maximum value of the elements: ";
    cin >> maxVal;
    int *arr = new int[n];  
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    countingSort(arr, n, minVal, maxVal);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
