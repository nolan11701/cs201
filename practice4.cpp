#include <iostream>
using namespace std;

#define N 5
int arr[N];
int v[N];
void lucky_box(int num) {
    if (num == 3) {
        for (int i = 0; i < 3; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (v[i] == 0) {
            arr[num] = i;
            v[i] = 1;
            lucky_box(num + 1);
            v[i] = 0;
        }
    }
}

int main() { lucky_box(0); }