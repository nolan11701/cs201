#include <iostream>
#include <vector>
using namespace std;

int n, startP, endP;
vector<int> visited(200, INT16_MAX);
int jump[201];
int dx[2] = {1, -1};

void dfs(int x){
    if (x == endP)
        return;
    
    int step = visited[x];
    for (int i = 0; i < 2; i++){
        int nx = x + dx[i]*jump[x];
        if (0 <= nx && nx < n && step + 1 < visited[nx]){
            visited[nx] = step + 1;
            dfs(nx);
        }
    }
}

int main(){
    cin >> n >> startP >> endP;
    startP--; endP--;
    for (int i = 0; i < n; i++){
        cin >> jump[i];
    }
    visited[startP] = 0;
    dfs(startP);
    
    if(visited[endP] != INT16_MAX){
        cout << visited[endP] << "\n";
    } else {
        cout << "-1" << "\n";
    }
}