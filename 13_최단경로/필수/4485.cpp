#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 987654321;
typedef tuple<int, int, int> tp;

int dijkstra(int n, vector<vector<int>> &arr){
  vector<vector<int>>dist(n, vector<int>(n, INF)); // 각 정점까지의 최단 거리 저장
  priority_queue<tp, vector<tp>, greater<>> pq; // 0: 거리, 1: 행, 2: 열

  dist[0][0] = arr[0][0];
  pq.push({arr[0][0], 0, 0});

  while(!pq.empty()){
    int weight = get<0>(pq.top());
    int x = get<1>(pq.top());
    int y = get<2>(pq.top());
    pq.pop();

    if(weight > dist[x][y]){
      continue;
    }

    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, -1, 0, 1};

    for(int i = 0; i < 4; i++){
      int new_x = x + dx[i];
      int new_y = y + dy[i];

      if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n){
        int next_weight = weight + arr[new_x][new_y];
        if(next_weight < dist[new_x][new_y]){
          dist[new_x][new_y] = next_weight;
          pq.push({next_weight, new_x, new_y});
        }
      }
    }
  }
  return dist[n-1][n-1];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, t;
  for(int t = 1;; t++){
    cin >> n;
    if(n == 0){
      break;
    }
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> arr[i][j];
      }
    }

  cout << "Problem " << t << ": " << dijkstra(n, arr) << "\n";
  }
  return 0;
}