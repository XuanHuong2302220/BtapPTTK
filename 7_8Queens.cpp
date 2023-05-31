#include <iostream>
#include <vector>
using namespace std;

const int n = 8;
vector<int> col(n);
vector<int> diag1(2*n-1);
vector<int> diag2(2*n-1);
int count = 0;

void search(int y) {
    if (y == n) { // Tìm được 1 giải pháp
        count++;
        return;
    }

    for (int x = 0; x < n; x++) { // Thử đặt 1 quân hậu vào mỗi cột của hàng y
        if (col[x] || diag1[x+y] || diag2[x-y+n-1]) {
            continue; // Ô (x, y) đã bị chiếm
        }

        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1; // Đánh dấu ô (x, y) là đã chiếm
        search(y+1); // Đệ quy tìm nước đi tiếp theo trên hàng y+1
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0; // Hủy đánh dấu ô (x, y) là đã chiếm
    }
}

int main() {
    search(0);
    cout << "Number of solutions: " << count << endl;
    return 0;
}

