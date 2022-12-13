#include <iostream>
using namespace std;

int n;
int global = INT16_MAX;

int visited[100][100];
int board[100][100];

bool can_move(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (visited[row][i] != 0 || visited[i][col] != 0) {
            return false;
        }
    }
    return true;
}
void dfs(int rowindex, int now) {
    if (rowindex == n) {
        global = min(global, now);
        return;
    }

    if (now > global) return;

    for (int colindex = 0; colindex < n; colindex++) {
        if (can_move(rowindex, colindex)) {
            visited[rowindex][colindex] = 1;
            dfs(rowindex + 1, now + board[rowindex][colindex]);
            visited[rowindex][colindex] = 0;
        }
    }
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    dfs(0, 0);
    cout << global;
}