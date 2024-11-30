#include <iostream>
#include <algorithm>
using namespace std;
void knapsack(int v[], int w[], int n, int W) 
{
    int c[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (w[i - 1] <= j) {
                c[i][j] = max(v[i - 1] + c[i - 1][j - w[i - 1]], c[i - 1][j]);
            } else {
                c[i][j] = c[i - 1][j];
            }
        }
    }
    cout << "Maximum value in the knapsack: " << c[n][W] << endl;
    int i = n, j = W;
    cout << "Items included in the knapsack are: ";
    while (i > 0 && j > 0) {
        if (c[i][j] != c[i - 1][j]) {
            cout << i << " "; 
            j -= w[i - 1];
        }
        i--;
    }
    cout << endl;
}
int main() 
{
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    int v[n], w[n];
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    knapsack(v, w, n, W);
    return 0;
}
