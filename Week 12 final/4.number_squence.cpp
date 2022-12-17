#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<int> list;

void dfs(int index, string output, int current, int sum, int sign) {
  //cout << index << "," << output<< ","<< current<<","<<sum <<"," << sign << "."<< endl;
  if(index == n-1){
    output += to_string(list[n-1]);
    sum = sum + (current*10 + list[n-1])*sign;
    //cout << "sum="<< sum <<", "<< output << endl;
    if(sum==0) {
      cout<< output << endl;
    }
    return;
  }
  output += to_string(list[index]);
  int new_current = current*10 + list[index];
  dfs(index+1, output + " ", new_current, sum, sign);
  int new_sum = sum + sign*new_current;
  dfs(index+1, output + "+", 0, new_sum, 1);
  dfs(index+1, output + "-", 0, new_sum, -1);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    list.push_back(i+1);
  }
  dfs(0,"",0,0,1);
  
}