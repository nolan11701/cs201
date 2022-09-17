#include <iostream>
using namespace std;

int test[8] = {23, 14, 55, 7, 12, 43, 28, 35};
int best[8] = {};

int main() {
    for (int i; i<=8; i++){
        if (test[i]>best[i-1]){
            best[i] = test[i];
        }
    }
    cout << best[7];
}

