#include <iostream>
using namespace std;

int n;
int arr[10];
int v[10];
int p;
int c = 0;
void combination(int k) {
    if (k == n) {
        c++;
        if (c == p) {
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
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
    cin >> n >> p;
    combination(0);
}