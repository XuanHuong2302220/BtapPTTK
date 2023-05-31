#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> val, int n) {
    int K[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int W = 50; // Trọng lượng tối đa của balo
    vector<int> wt = {10, 20, 30}; // Trọng lượng của các vật phẩm
    vector<int> val = {60, 100, 120}; // Giá trị của các vật phẩm
    int n = wt.size(); // Số lượng vật phẩm

    int maxValue = knapsack(W, wt, val, n);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}

