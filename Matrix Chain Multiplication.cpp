#include <iostream>
#include <limits>
using namespace std;
int matrixChainOrder(int p[], int n, int s[][10]) 
{
  int dp[n][n];
  for (int i = 1; i < n; i++) 
  {
    dp[i][i] = 0;
  }
  for (int l = 2; l < n; l++) 
  {
    for (int i = 1; i < n - l + 1; i++) 
    {
      int j = i + l - 1;
      dp[i][j] = numeric_limits<int>::max();
      for (int k = i; k < j; k++) 
      {
        int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < dp[i][j]) 
        {
          dp[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
  return dp[1][n - 1];
}
void printOptimalParenthesization(int s[][10], int i, int j) 
{
  if (i == j) 
  {
    cout << "A" << i;
  } 
  else 
  {
    cout << "(";
    printOptimalParenthesization(s, i, s[i][j]);
    printOptimalParenthesization(s, s[i][j] + 1, j);
    cout << ")";
  }
}
int main() 
{
  int n;
  cout << "Enter the number of matrices: ";
  cin >> n;
  int p[n + 1];
  cout << "Enter the dimensions (p0, p1, ..., pn):\n";
  for (int i = 0; i <= n; i++) 
  {
    cin >> p[i];
  }
  int s[10][10] = {0};
  int minMultiplications = matrixChainOrder(p, n + 1, s);
  cout << "Minimum number of multiplications is: " << minMultiplications << endl;
  cout << "Optimal Parenthesization is: ";
  printOptimalParenthesization(s, 1, n);
  cout << endl;
  return 0;
}
