#include <bits/stdc++.h>

using namespace std;

vector<int> add_polynomial(const vector<int>& A, const vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<int> C(max(n, m));
    for (int i = 0; i < max(n, m); i++) {
        C[i] = ((i < n) ? A[i] : 0) + ((i < m) ? B[i] : 0);
    }
    return C;
}

vector<int> sub_polynomial(const vector<int>& A, const vector<int>& B) {
    int n = A.size(), m = B.size();
    vector<int> C(max(n, m));
    for (int i = 0; i < max(n, m); i++) {
        C[i] = ((i < n) ? A[i] : 0) - ((i < m) ? B[i] : 0);
    }
    return C;
}

vector<int> multiply_polynomial(const vector<int>& A, const vector<int>& B) {
    int n = A.size(), m = B.size();
    if (n < m) {
        return multiply_polynomial(B, A);
    }
    if (n == 1) {
        vector<int> C(1);
        C[0] = A[0] * B[0];
        return C;
    }
    int k = (n + 1) / 2;
    vector<int> A1(A.begin(), A.begin() + k);
    vector<int> A2(A.begin() + k, A.end());
    vector<int> B1(B.begin(), B.begin() + min(m, k));
    vector<int> B2(B.begin() + min(m, k), B.end());
    vector<int> C1 = multiply_polynomial(A1, B1);
    vector<int> C2 = multiply_polynomial(A2, B2);
    vector<int> A3 = add_polynomial(A1, A2);
    vector<int> B3 = add_polynomial(B1, B2);
    vector<int> C3 = multiply_polynomial(A3, B3);
    vector<int> C4 = sub_polynomial(sub_polynomial(C3, C1), C2);
    vector<int> C(n + m - 1);
    for (int i = 0; i < C1.size(); i++) {
        C[i] += C1[i];
    }
    for (int i = 0; i < C2.size(); i++) {
        C[i + 2 * k] += C2[i];
    }
    for (int i = 0; i < C4.size(); i++) {
        C[i + k] += C4[i];
    }
    return C;
}

void print_polynomial(const vector<int>& polynomial) {
    int n = polynomial.size();
    for (int i = 0; i < n; i++) {
        cout << polynomial[i];
        if (i < n - 1) {
            cout << "x^" << n - 1 - i << " + ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> A = {1, 2, 3}; // Đa thức A = 3x^2 + 2x + 1
    vector<int> B = {4, 5, 6, 7}; // Đa thức B = 7x^3 + 6x^2 + 5x + 4

    cout << "A: ";
    print_polynomial(A);
    cout << "B: ";
    print_polynomial(B);

    vector<int> sum = add_polynomial(A, B);
    cout << "Sum: ";
    print_polynomial(sum);

    vector<int> diff = sub_polynomial(A, B);
    cout << "Difference: ";
    print_polynomial(diff);

    vector<int> product = multiply_polynomial(A, B);
    cout << "Product: ";
    print_polynomial(product);

    return 0;
}

