#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int p[n][n+1];
    p[0][1] = 1;
    for (int i; i<n; i++){
        for (int j; i<n++; i++){
            p[i][j]= p[i-1][j-1] + p[i-1][j];
        }
            
    }
}
