#include <iostream>
#include <vector>
using namespace std;

int n, l, i;
vector<string> vec;

void dfs(string &st, int count) {
    if (st.size() > n || vec.size() > i || count > l){
        return;
    }
    if (st.size() == n){
        vec.push_back(st);
    }

    string s0 = st + "0";
    dfs(s0, count);
    string s1 = st + "1";
    dfs(s1, count+1);
} 

int main(){
    cin >> n >> l >> i;
    string st; 
    dfs(st, 0);
    cout << vec[i-1];
}