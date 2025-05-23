#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > matrix;


// 청소해야 하는 칸이 있는 지 검사하는 로직
bool checkClean(matrix &room, int x, int y, int n, int m){
  vector<int> dx(4);
  dx[0] = -1; dx[1] = 1; dx[2] = 0; dx[3] = 0;
  vector<int> dy(4);
  dy[0] = 0; dy[1] = 0; dy[2] = 1; dy[3] = -1;


  for(int i = 0; i < 4; i++){
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m){
      continue;
    }
    if(room[new_x][new_y] == 0){
      return true;
    }
  }
  return false;
}


// 청소하는 칸의 개수를 세는 함수
int countClean(matrix &room, int n, int m, int r, int c, int d){
  int count = 0;
  while(true){
    // 현재 칸을 청소해야 하는 경우, 청소하고 상태 업데이트
    if(room[r][c] == 0){
      count++;
      room[r][c] = 2;
    }

    // 주변 칸 중 청소할 칸이 없는 경우 이동
    if(!checkClean(room, r, c, n, m)){
      if(d == 0){ // 북쪽인 경우 아래로 한 칸 이동(행 증가)
        // 후진할 수 없다면 작동 멈춤
        if(room[r + 1][c] == 1){
          break;
        }
        r++;
      }
      else if(d == 1){ // 동쪽인 경우 왼쪽으로 한 칸 이동(열 감소)
        if(room[r][c - 1] == 1){
            break;
        }
        c--;
      }
      else if(d == 2){ // 남쪽인 경우 위로 한 칸 이동(행 감소)
        if(room[r - 1][c] == 1){
          break;
        }
        r--;
      }
      else{ // 서쪽인 경우 오른쪽으로 한 칸 이동(열 증가)
        if(room[r][c + 1] == 1){
          break;
        }
        c++;
      }
    }
    else{ // 주변에 청소할 칸이 있는 경우
      // 반시계 방향으로 회전
      if(d == 0){ // 북쪽인 경우 서쪽
        d = 3;
        // 앞 칸이 청소할 수 있는 칸인지 확인
        if(room[r][c - 1] == 0){
            c--;
        }
      }
      else if(d == 1){ // 동쪽인 경우 북쪽
        d = 0;
        // 앞 칸이 청소할 수 있는 칸인지 확인
        if(room[r - 1][c] == 0){
            r--;
        }
      }
      else if(d == 2){ // 남쪽인 경우 동쪽
        d = 1;
        // 앞 칸이 청소할 수 있는 칸인지 확인
        if(room[r][c + 1] == 0){
          c++;
        }
      }
      else{ // 서쪽인 경우 남쪽
        d = 2;
        // 앞 칸이 청소할 수 있는 칸인지 확인
        if(room[r + 1][c] == 0){
          r++;
        }
      }
    }
  }
  return count;
}

int main(){
  int n, m, r, c, d;
  cin >> n >> m >> r >> c >> d;

  matrix room(n, vector<int>(m, 0));

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> room[i][j];
    }
  }
  cout << countClean(room, n, m, r, c, d) << "\n";
}