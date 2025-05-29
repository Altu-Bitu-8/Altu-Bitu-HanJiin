#include <iostream>
#include <vector>

using namespace std;

int floydWarshall(int n, vector<vector<int>> &height){
  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(height[i][k] == 1 && height[k][j] == 1){
          height[i][j] = 1; 
        }
      }
    }
  }
  int count = 0;
  vector<int> before(n+1, 0);
  vector<int> after(n+1, 0);
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(height[j][i] == 1){
        before[i]++;
      }
      if(height[i][j] == 1){
        after[i]++;
      }
    }
    if(before[i] + after[i] == n -1){
      count++;
    }
  }
  return count;
}

int main(){ 
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m, a, b;
  cin >> n >> m;

  vector<vector<int>> height(n+1, vector<int>(n+1, 0));

  while(m--){
    cin >> a >> b;
    height[a][b] = 1;
  }
  cout << floydWarshall(n, height) << "\n";
  return 0;
}