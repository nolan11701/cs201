#include <iostream>
using namespace std;

int n;
int arr[10];
int v[10];
int p;
void combination(int k) {
    if (k == n) {
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += arr[i];
        }
        if (s % p == 0) {
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for (int i = 1; i <= n; i++) {
        //   if (v[i] == 0) {
        arr[k] = i;
        // v[i] = 1;
        combination(k + 1);
    }
}

int main() {
    cin >> n >> p;
    combination(0);
}