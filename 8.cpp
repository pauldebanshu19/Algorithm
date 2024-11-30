#include <iostream>
#include <iomanip>
using namespace std;
void fractionalKnapsack(int n, double w[], double p[], double W) 
{
    double x[n]; 
    for (int i = 0; i < n; i++) 
    {
        x[i] = 0;
    }
    double weight = 0; 
    double totalProfit = 0; 
    for (int i = 0; i < n; i++) 
    {
        if (weight + w[i] <= W) { 
            x[i] = 1;
            weight += w[i];
            totalProfit += p[i];
        } else {
            x[i] = (W - weight) / w[i];
            totalProfit += x[i] * p[i];
            weight = W; 
            break;
        }
    }
    cout << fixed << setprecision(2); 
    cout << "Maximum profit: " << totalProfit << endl;
    cout << "Fractions of items taken: ";
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}
int main() 
{
    int n;
    double W;
    cout << "Enter the number of items: ";
    cin >> n;
    double w[n], p[n];
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    cout << "Enter the profits of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = p[i] / w[i];
            double r2 = p[j] / w[j];
            if (r1 < r2) {
                double tempW = w[i];
                w[i] = w[j];
                w[j] = tempW;
                double tempP = p[i];
                p[i] = p[j];
                p[j] = tempP;
            }
        }
    }
    fractionalKnapsack(n, w, p, W);
    return 0;
}