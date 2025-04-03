#include <iostream>
#include <vector>

using namespace std;

// 돌아가는 지 확인해서 vector에 바퀴 인덱스와 방향 insert
vector<pair<int, int>> spinningWheels(vector<vector<int>> &wheel, int n, int direction)
{
    int index = n - 1, new_direction;
    vector<pair<int, int>> spinning_wheels;
    spinning_wheels.push_back(make_pair(index, direction));
    // 현재 바퀴의 왼쪽을 확인함
    new_direction = direction;
    for (int i = index; i > 0; i--){
        // 현재 바퀴의 9시 방향 극과 전의 바퀴의 3시 방향 극을 비교
        if (wheel[i][6] != wheel[i - 1][2]){
            // 현재 인덱스 바퀴의 회전 방향과 반대
            new_direction *= -1;
            spinning_wheels.push_back(make_pair(i - 1, new_direction));
        }
        else{
            break;
        }
    }
    // 현재 바퀴의 오른쪽을 확인함
    new_direction = direction;
    for (int i = index; i < wheel.size() - 1; i++){
        // 현재 바퀴의 3시 방향 극과 9시 방향 극을 비교
        if (wheel[i][2] != wheel[i + 1][6]){
            // 현재 인덱스 바퀴의 회전 방향과 반대
            new_direction *= -1;
            spinning_wheels.push_back(make_pair(i + 1, new_direction));
        }
        else{
            break;
        }
    }
    return spinning_wheels;
}

// 회전 함수
void rotate(vector<vector<int>> &wheel, vector<pair<int, int>> &spinning_wheels)
{
    for (auto iter : spinning_wheels){
        // 시계 방향으로 회전하는 경우
        // 오른쪽으로 한 칸씩 이동
        if (iter.second == 1){
            int temp = wheel[iter.first][7];
            for (int i = 6; i >= 0; i--){
                wheel[iter.first][i + 1] = wheel[iter.first][i];
            }
            wheel[iter.first][0] = temp;
        }
        // 반시계 방향으로 회전하는 경우
        // 왼쪽으로 한 칸씩 이동
        else
        {
            int temp = wheel[iter.first][0];
            for (int i = 1; i < 8; i++){
                wheel[iter.first][i - 1] = wheel[iter.first][i];
            }
            wheel[iter.first][7] = temp;
        }
    }
}

// S극 개수 출력
int countS(vector<vector<int>> &wheel)
{
    int cnt = 0;
    for (int i = 0; i < wheel.size(); i++){
        if (wheel[i][0] == 1){
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;

    vector<vector<int>> wheel(t, vector<int>(8));
    for (int i = 0; i < t; i++){
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++){
            wheel[i][j] = s[j] - '0';
        }
    }

    int k;
    cin >> k;
    vector<pair<int, int>> way(k);
    vector<pair<int, int>> spinning_wheels;

    for (int i = 0; i < k; i++){
        cin >> way[i].first >> way[i].second;
    }

    for (int i = 0; i < k; i++){
        spinning_wheels = spinningWheels(wheel, way[i].first, way[i].second);
        rotate(wheel, spinning_wheels);
    }

    // 계산
    int result = countS(wheel);

    // 출력
    cout << result;
    return 0;
}