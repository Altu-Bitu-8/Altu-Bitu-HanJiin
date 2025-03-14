#include <iostream>
#include <tuple>

using namespace std;

tuple<char, char, int, int> chessMove(char king_index, char stone_index, int king_num, int stone_num, string move){
    if(move == "R"){
        // 돌이 그 자리에 있을 경우
        if(char(king_index + 1) == stone_index && king_num == stone_num){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_index + 1) < 73){
                stone_index = char(stone_index + 1);
                king_index = char(king_index + 1);
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_index + 1) < 73){
            king_index = char(king_index + 1);
        }
    }
    else if(move == "L"){
        // 돌이 그 자리에 있을 경우
        if(char(king_index - 1) == stone_index && king_num == stone_num){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_index - 1) > 64){
                stone_index = char(stone_index - 1);
                king_index = char(king_index - 1);
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_index - 1) > 64){
            king_index = char(king_index - 1);
        }
    }
    else if(move == "B"){
        // 돌이 그 자리에 있을 경우
        if((king_num - 1) == stone_num && king_index == stone_index){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_num - 1) > 0){
                stone_num -= 1;
                king_num -= 1;
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_num - 1) > 0){
            king_num -= 1;
        }
    }
    else if(move == "T"){
        // 돌이 그 자리에 있을 경우
        if((king_num + 1) == stone_num && king_index == stone_index){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_num + 1) < 9){
                stone_num += 1;
                king_num += 1;
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_num + 1) < 9){
            king_num += 1;
        }
    }
    else if(move == "RT"){
        // 돌이 그 자리에 있을 경우
        if(char(king_index + 1) == stone_index && (king_num + 1) == stone_num){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_index + 1) < 73 && (stone_num + 1) < 9){
                stone_index = char(stone_index + 1);
                stone_num += 1;
                king_index = char(king_index + 1);
                king_num += 1;
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_index + 1) < 73 && (king_num + 1) < 9){
            king_index = char(king_index + 1);
            king_num += 1;
        }
    }
    else if(move == "LT"){
        // 돌이 그 자리에 있을 경우
        if(char(king_index - 1) == stone_index && (king_num + 1) == stone_num){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_index - 1) > 64 && (stone_num + 1) < 9){
                stone_index = char(stone_index - 1);
                stone_num += 1;
                king_index = char(king_index - 1);
                king_num += 1;
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_index - 1) > 64 && (king_num + 1) < 9){
            king_index = char(king_index - 1);
            king_num += 1;
        }
    }
    else if(move == "RB"){
        // 돌이 그 자리에 있을 경우
        if(char(king_index + 1) == stone_index && (king_num - 1) == stone_num){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_index + 1) < 73 && (stone_num - 1) > 0){
                stone_index = char(stone_index + 1);
                stone_num -= 1;
                king_index = char(king_index + 1);
                king_num -= 1;
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_index + 1) < 73 && (king_num - 1) > 0){
            king_index = char(king_index + 1);
            king_num -= 1;
        }
    }
    else if(move == "LB"){
        // 돌이 그 자리에 있을 경우
        if(char(king_index - 1) == stone_index && (king_num - 1) == stone_num){
            //돌이 범위를 벗어나지 않을 경우
            if((stone_index - 1) > 64 && (stone_num - 1) > 0){
                stone_index = char(stone_index - 1);
                stone_num -= 1;
                king_index = char(king_index - 1);
                king_num -= 1;
            }
        }
        //돌이 그 자리에 없고 킹이 범위를 벗어나지 않을 경우
        else if((king_index - 1) > 64 && (king_num - 1) > 0){
            king_index = char(king_index - 1);
            king_num -= 1;
        }
    }
    return { king_index, stone_index, king_num, stone_num };
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string king, stone;
    int n;

    cin >> king >> stone >> n;
    string move;
    char king_index = king[0];
    char stone_index = stone[0];

    int king_num = king[1] - '0';
    int stone_num = stone[1] - '0';

    while(n--){
        cin >> move;
        tie(king_index, stone_index, king_num, stone_num ) = chessMove(king_index, stone_index, king_num, stone_num, move);
    }
    cout << king_index << king_num << "\n";
    cout << stone_index << stone_num << "\n";


    return 0;
}