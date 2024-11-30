#include <iostream>
#include <string>
using namespace std;
void computeLPSArray(const string &pattern, int *lps) 
{
    int length = 0; 
    lps[0] = 0;     
    int i = 1;

    while (i < pattern.size()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(const string &pattern, const string &text) 
{
    int m = pattern.size();
    int n = text.size();    
    int *lps = new int[m];
    computeLPSArray(pattern, lps);
    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    delete[] lps;
}
int main() 
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern: ";
    cin >> pattern;
    KMPSearch(pattern, text);
    return 0;
}