#include <iostream>
using namespace std;

int triple_fib(int n){
    if (n <= 3 ){
        return 1;
    }
    return triple_fib(n-1) + triple_fib(n-2) + triple_fib(n-3);
}

int main(){
    int n;
    cin >> n;
    cout << triple_fib(n);
}