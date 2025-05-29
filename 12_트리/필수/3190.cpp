#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> pi;

int snakeMove(vector<vector<int>> &board, vector<char> &move){
  int n = board.size() - 1;
  //오른쪽, 위쪽, 왼쪽, 아래쪽
  int dx[4] = {0, -1, 0, 1}; 
  int dy[4] = {1, 0, -1, 0}; 
  int dir = 0;
  int second = 0;

  deque<pi> snake;
  snake.push_back({1, 1});

  vector<vector<int>> body(n+1, vector<int>(n+1, 0));
  body[1][1] = 1;
  while(true && !snake.empty()){
    second++;
    int nx = snake.back().first + dx[dir];
    int ny = snake.back().second + dy[dir];

    // 벽에 부딪히면 종료
    if(nx <= 0 || nx > n || ny <= 0 || ny > n){
      break;
    }

    // 자신의 몸에 부딪히면 종료
    if(body[nx][ny] == 1){
      break;
    }

    //사과가 있다면
    if(board[nx][ny] == 1){
      // 사과 먹기
      board[nx][ny] = 0;
      snake.push_back({nx, ny});
      body[nx][ny] = 1;
    }
    else{
      snake.push_back({nx, ny});
      body[nx][ny] = 1;
      body[snake.front().first][snake.front().second] = 0;
      snake.pop_front();
    }

    if(move[second] == 'D'){
      dir = (dir + 3) % 4;
    }
    else if(move[second] == 'L'){
      dir = (dir + 1) % 4;
    }
  }
  return second;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, a1, a2, l, sec;
  char m;
  cin >> n >> k;

  vector<vector<int>> board(n+1, vector<int>(n+1, 0));
  while(k--){
    cin >> a1 >> a2;
    board[a1][a2] = 1;
  }
  
  cin >> l;
  vector<char> move(10001);
  while(l--){
    cin >> sec >> m;
    move[sec] = m;
  }

  cout << snakeMove(board, move) << "\n";;

  return 0;
}