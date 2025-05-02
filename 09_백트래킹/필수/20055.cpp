#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getLevel(int n, int k, vector<int> &a){
    int count = 0, start = 0, end = n - 1, level = 1;
    queue<int> robot_idx;
    vector<bool> robot_exists(2 * n, false);

    while(true){
        //컨베이어 벨트 회전 로직
        start = (start - 1 + 2 * n) % (2 * n);
        end = (end - 1 + 2 * n) % (2 * n);

        // 회전으로 end 위치에 도달한 로봇 제거
        if (!robot_idx.empty() && robot_idx.front() == end) {
            robot_exists[end] = false;
            robot_idx.pop();
        }

        // 로봇을 한 칸씩 이동시킨다.
        int size = robot_idx.size();
        while(size--){
            if(!robot_idx.empty()){
                int now = robot_idx.front();
                int next = (now + 1) % (2 * n);
                // 로봇 인덱스를 큐에서 꺼내서 이동할 수 있는 지 체크한다
                robot_idx.pop();
                if(a[next] > 0 && !robot_exists[next]){
                    // 인덱스를 갱신한다
                    robot_exists[now] = false;
                    if(next != end){
                        robot_exists[next] = true;
                        robot_idx.push(next);
                    }
                    a[next]--;
                    if(a[next] == 0){
                        count++;
                    }
                }
                else{
                    robot_idx.push(now);
                }
            }
        }

        // 회전 또는 이동 후 end에 도달한 로봇 제거
        if(!robot_idx.empty() && robot_idx.front() == end){
            robot_exists[end] = false;
            robot_idx.pop();
        }

        // 내구도가 0보다 크다면
        if(a[start] > 0 && !robot_exists[start]){
            // 로봇을 올린다(내구도 감소)
            robot_idx.push(start);
            a[start]--;
            robot_exists[start] = true;
            if(a[start] == 0){
                count++;
            }
        }
        if(count >= k){
            return level;
        }
        level++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<int> a(2 * n, 0);
    for(int i = 0; i < 2 * n; i++){
        cin >> a[i];
    }
    int level = getLevel(n, k, a);
    cout << level << "\n";
}
