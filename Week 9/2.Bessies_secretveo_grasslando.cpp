#include <iostream>
using namespace std;
int n, answer = 0;

void dfs(int index, int residual){
    if (index == 4){
        if (residual == 0){
            answer++;
        }
        return;
    }
    int now = 0;
    while (now * now <= residual){
        dfs(index + 1, residual - now * now);
        now++;
    }
}

int main(){
    scanf("%d", &n);
    dfs(0, n);
    printf("%d", answer);
}