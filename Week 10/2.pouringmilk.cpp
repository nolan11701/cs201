#include <iostream>
using namespace std;

int A, B,C; // capacity of bucket
int state[100][100][100];
int milk[100];
int total = 0; 
void dfs(int a, int b, int c) {
    // terminating condition 
    if (state[a][b][c] == 1){
        return;
    }
    state[a][b][c] = 1; // 1 visited 0 not visited 
    // count 
    if (a == 0) {
        milk[total] = c;
        //cout << c << "\n";
        total ++;
    }
    
    // wishful thinking

    // c->a 
    if (c> (A-a)) {
        dfs(A, b, c-(A-a));
    } else {
        dfs(a+c,b,0);
    }
    // c->b
    if (c> (B-b)) {
        dfs(a, B, c-(B-b));
    } else {
        dfs(a, b+c,0);
    }
    // a->c
    if (a > (C-c)){
        dfs(a-(C-c), b, C);
    } else {
        dfs(0, b, c+a);
    }
    // a->b
    if (a > (B-b)){
        dfs(a-(B-b), B, c);
    } else {
        dfs(0, b+a, c);
    }
    // b->a
    if (b > (A-a)){
        dfs(A, b-(A-a), c);
    } else {
        dfs(a+b, 0, c);
    }
    // b->c
    if (b > (C-c)){
        dfs(a, b-(C-c), C);
    } else {
        dfs(a, 0, b+c);
    }
  
}

void bubble_sort(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j+1]) {
                int mid = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = mid;
            }
}
int main() {
    cin >> A >> B >> C;
    // 8 9 10
    dfs(0,0,C);
    bubble_sort(milk, total);
    for (int i=0;i<total;i++){
        cout << milk[i] << " ";
    }
    //cout << total;
 
}