#include <iostream>
using namespace std;

int n;
int total;
 
void dfs(int num) {
    // terminating condition 
    if (num > n){
        return;
    }
    // wishful thinking
    total++; 
    dfs(10*num);
    dfs(10*num+1);
  
}
int main() {
    cin >> n;

    dfs(1);
    cout << total;
 
}