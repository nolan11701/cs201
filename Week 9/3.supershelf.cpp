# include <iostream>
using namespace std;

int n, b, ans = INT16_MAX, height = 0;
int cow[25];
bool visited[25];

void dfs(){
    if(height > b){
        ans = min(ans, height);
        return;
    }
    for (int i = 0; i< n; i++){
        if (visited[i] == 0){
            visited[i] = 1;
            height += cow[i];
            dfs();
            visited[i] = 0;
            height -= cow[i];
        }
    }
}

int main(){
    cin >> n >> b;
    for (int i=0; i< n; i++){
        cin>> cow[i];
    }
    dfs();
    cout << ans-b;
}