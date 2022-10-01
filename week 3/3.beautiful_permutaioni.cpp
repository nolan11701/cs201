#include <iostream>
using namespace std;

int n;
int arr[10];
int v[10];
int p;
int c = 0;
void combination(int k) {
    if (k == n) {
        bool v = true;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == 1 || arr[i] - arr[i - 1] == -1) {
                v = false;
            }
        }

        if (v) c++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            arr[k] = i;
            v[i] = 1;
            combination(k + 1);
            v[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    combination(0);
    cout << c;
}