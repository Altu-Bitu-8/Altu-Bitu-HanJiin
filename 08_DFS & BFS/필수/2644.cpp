#include <iostream>
#include <queue>

using namespace std;

int n, m, num1, num2;
int graph[101][101] = {0, };
bool visited[10001] = {false, };
int dist[101] = {0};
int cnt = 0;

void bfs(int from, int to){
    visited[from] = true;

    queue<int> q;
    q.push(from);

    while(!q.empty()){
        int now = q.front();
        q.pop();

        // 시작점에서 끝점에 다다르면 return
        if(now == to){
            cnt = dist[to];
            return;
        }
        
        for(int i = 1; i <= n; i++){
            if(graph[now][i] == 1&& !visited[i]){
                visited[i] = true;
                // 촌수 갱신
                dist[i] = dist[now] + 1;
                q.push(i);
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> num1 >> num2;
    cin >> m;

    for(int i = 1; i <= m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
    }

    bfs(num1, num2);

    // 촌수 존재 x 시 -1 출력
    if(cnt == 0){
        cout << "-1\n";
    } else{
        cout << cnt << "\n";
    }
}