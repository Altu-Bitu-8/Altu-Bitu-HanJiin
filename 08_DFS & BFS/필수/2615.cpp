#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    vector<vector<int> > board;
    board.assign(19, vector<int>(19));
    bool win = false;

    for(int i = 0; i < 19; i++){
        for(int j = 0; j < 19; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < 19; i++){
        if(win == true){
            break;
        }
        for(int j = 0; j < 19; j++){
            if(board[i][j] == 0){
                continue;
            }

            // 오른쪽이 같은 색깔
            if(j < 18 && board[i][j+1] == board[i][j]){
                if (j > 0 && board[i][j-1] == board[i][j]){
                } else{
                    for(int k = 2; k <= 5; k++){
                        // 체크 로직
                            if(j + k > 18){
                                if(k != 5){
                                    win = false;
                                }
                                break;
                            }
                            if(board[i][j+k] != board[i][j] && k != 5){
                                win = false;
                                break;
                            }
                            else if(board[i][j+k] == board[i][j] && k == 5){
                                win = false;
                                break;
                            }
                            else{
                                win = true;
                            }    
                    }
                    if(win == true){
                        cout << board[i][j] << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        break;
                    }
                }
            }
            // 아래쪽이 같은 색깔
            if(i < 18 && board[i+1][j] == board[i][j]){
                if (i > 0 && board[i-1][j] == board[i][j]){
                } else {
                    for(int k = 2; k <= 5; k++){
                        // 체크 로직
                        if(i + k > 18){
                            if(k != 5){
                                win = false;
                            }
                            break;
                        }
                        if(board[i+k][j] != board[i][j] && k != 5){
                            win = false;
                            break;
                        }
                        else if(board[i+k][j] == board[i][j] && k == 5){
                            win = false;
                            break;
                        }
                        else{
                            win = true;
                        }
                    }
                    if(win == true){
                        cout << board[i][j] << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        break;
                    }
                }
            }    
            // 오른쪽 대각선 아래가 같은 색깔
            if(i < 18 && j < 18 && board[i+1][j+1] == board[i][j]){
                if (i > 0 && j > 0 && board[i-1][j-1] == board[i][j]){
                } else{
                    for(int k = 2; k <= 5; k++){
                        // 체크 로직
                        if(i + k > 18 || j + k > 18){
                            if(k != 5){
                                win = false;
                            }
                            break;
                        }
                        if(board[i+k][j+k] != board[i][j] && k !=5){
                            win = false;
                            break;
                        }
                        else if(board[i+k][j+k] == board[i][j] && k == 5){
                            win = false;
                            break;
                        }
                        else{
                            win = true;
                        }
                    }
                    if(win == true){
                        cout << board[i][j] << "\n";
                        cout << i + 1 << " " << j + 1 << "\n";
                        break;
                    }
                }
            }
            // 왼쪽 대각선 아래가 같은 색깔
            if(j > 0 && i < 18 && board[i+1][j-1] == board[i][j]){
                if (i > 0 && j < 18 && board[i-1][j+1] == board[i][j]){
                } else {
                    for(int k = 2; k <= 5; k++){
                    // 체크 로직
                        if(j - k < 0 || i + k > 18){
                            if(k != 5){
                                win = false;
                            }
                            break;
                        }
                        if(board[i+k][j-k] != board[i][j] && k != 5){
                            win = false;
                            break;
                        }
                        else if(board[i+k][j-k] == board[i][j] && k == 5){
                            win = false;
                            break;
                        }
                        else{
                            win = true;
                        }    
                    }
                    if(win == true){
                        cout << board[i][j] << "\n";
                        cout << i + 5 << " " << j - 3 << "\n";
                        break;
                    }
                }
            }
        }
    } 
    if(win == false){
        cout << "0\n";
    }
    return 0;   
}