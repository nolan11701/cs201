#include <iostream>
using namespace std;

#define maxn 10000
int n, ans;
bool vis[maxn];
struct node
{
    int x, y;
};

node a[maxn];

// 1 is up
// 2 is down
// 3 is left
// 4 is right

void dfs(int x, int y, int c, int p) {
    if (c == n) {
        if (x == 0 && y > 0 && p != 2){
            ans++;
            return;
        }
        if (x == 0 && y < 0 && p != 1){
            ans++;
            return;
        }
        if (y == 0 && x > 0 && p != 3){
            ans++;
            return;
        }
        if (y == 0 && x < 0 && p != 4){
            ans++;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis [i]) continue;
        if (a[i].x > x && a[i].y == y && p != 4){
            vis [i] = 1;
            dfs(a[i].x, a[i].y, c+1, 4);
            vis[i] = 0;
        }
        if (a[i].x < x && a[i].y == y && p != 3){
            vis [i] = 1;
            dfs(a[i].x, a[i].y, c+1, 3);
            vis[i] = 0;
        }
        if (a[i].x == x && a[i].y < y && p != 2){
            vis [i] = 1;
            dfs(a[i].x, a[i].y, c+1, 2);
            vis[i] = 0;
        }
        if (a[i].x == x && a[i].y > y && p != 1){
            vis [i] = 1;
            dfs(a[i].x, a[i].y, c+1, 1);
            vis[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }

    dfs(0, 0, 0, 0);
    cout << ans;
}