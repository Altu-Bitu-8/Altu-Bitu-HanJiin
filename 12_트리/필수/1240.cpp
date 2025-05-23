#include <iostream>
#include <vector>
#include <map>

using namespace std;

int dfs(int cur, int target, vector<map<int, int> > &graph, vector<int> &visited, int dist){
  if(cur == target){
    return dist;
  }

  visited[cur] = true;

  for(auto &iter : graph[cur]){
    int next = iter.first;
    int weight = iter.second;
    if(visited[next]){
      continue;
    }
    int res = dfs(next, target, graph, visited, dist + weight);
    if (res != -1){
      return res;
    }
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m, v1, v2, w, m1, m2;
  cin >> n >> m;

  vector<map<int, int> > graph(n + 1);
  for(int i = 0; i < n - 1; i++){
    cin >> v1 >> v2 >> w;
    graph[v1][v2] = w;
    graph[v2][v1] = w;
  }


  for(int i = 0; i < m; i++){
    cin >> m1 >> m2;
    vector<int> visited(n+1 , 0);
    // 각각 dfs 해서 출력하기
    int answer = dfs(m1, m2, graph, visited, 0);
    cout << answer << "\n";
  }

  return 0;
}