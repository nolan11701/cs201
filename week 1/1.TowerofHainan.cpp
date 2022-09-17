#include <iostream>
#include <cmath>
using namespace std;

int tot = 0;

void move(int n, int src, int mid, int dst) {
    if (n == 1){
        cout << to_string(src) << " " << to_string(dst) << "\n";
        tot ++;
    } else {
        move(n-1, src, dst, mid);
        cout << to_string(src) << " " << to_string(dst) << "\n";
        tot ++;
        move(n-1, mid, src, dst);

    }
    
}

int main(){
    int a;
    cin >> a;
    cout << pow(2, a)-1 << "\n";
    
    move(a, 1,2,3);
    //cout << tot;
}

