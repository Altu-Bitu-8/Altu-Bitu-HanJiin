#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;

    int graph[101][101] = {0, };
    bool visited[10001] = {false, };

    for(int i = 1; i <= m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1;
    }

    visited[1] = true;
    queue<int> q;
    q.push(1);
    int now, cnt = 0;

    while(!q.empty()){
        now = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(graph[now][i] == 1 && !visited[i]){
                visited[i] = true;
                // 연결되어 있는 컴퓨터마다 카운트 증가
                cnt++;
                q.push(i);
            }
        }
    }
    cout << cnt << "\n";
}