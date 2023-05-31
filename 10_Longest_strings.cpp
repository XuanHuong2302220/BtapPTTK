#include <iostream>
#include <string>
using namespace std;

int lcs(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    else if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}

int main()
{
    string X, Y;
    cout << "Enter string X: ";
    cin >> X;
    cout << "Enter string Y: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    int lcsLength = lcs(X, Y, m, n);
    cout << "Length of the Longest Common Subsequence: " << lcsLength << endl;

    return 0;
}
