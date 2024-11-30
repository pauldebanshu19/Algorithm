#include <iostream>
#include <string>
using namespace std;
void LCS_LENGTH(const string& X, const string& Y, int** c, char** b, int m, int n) 
{
    for (int i = 0; i <= m; i++) 
    {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) 
    {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'D'; 
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'U'; 
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'L'; 
            }
        }
    }
}
void printLCS(char** b, const string& X, int i, int j) 
{
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == 'D') {
        printLCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == 'U') {
        printLCS(b, X, i - 1, j);
    } else {
        printLCS(b, X, i, j - 1);
    }
}
int main() 
{
    string X, Y;
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;
    int m = X.length();
    int n = Y.length();
    int** c = new int*[m + 1];
    char** b = new char*[m + 1];
    for (int i = 0; i <= m; i++) 
    {
        c[i] = new int[n + 1];
        b[i] = new char[n + 1];
    }
    LCS_LENGTH(X, Y, c, b, m, n);
    cout << "Length of LCS: " << c[m][n] << endl;
    cout << "LCS: ";
    printLCS(b, X, m, n);
    cout << endl;
    for (int i = 0; i <= m; i++) 
    {
        delete[] c[i];
        delete[] b[i];
    }
    delete[] c;
    delete[] b;
    return 0;
}