#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 0;
        }
        for (int k = 0; k <= i; k++) {
            cin >> m[i][k];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            m[i][j] += max(m[i + 1][j], m[i + 1][j + 1]);
        }
    }

    cout << m[0][0];
}