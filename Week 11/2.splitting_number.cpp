#include <iostream>
#include <vector>
using namespace std;

int n;

void dfs(int sum, vector<int> vec) {
    if (sum == n && vec.size() > 1) {
        printf("%d=", n);
        for (int i = 0; i < vec.size(); i++) {
            printf("%d", vec[i]);
            if (i != vec.size() - 1) {
                printf("+");
            }
        }
        printf("\n");
        return;
    }

    if (sum > n) return;
    int curr = vec.size() == 0 ? 1 : vec.back();

    for (int i = curr; i <= n - sum; i++) {
        vector<int> copy = vec;
        copy.push_back(i);
        dfs(sum + i, copy);
    }
}

int main() {
    cin >> n;
    vector<int> vec;
    dfs(0, vec);
}
