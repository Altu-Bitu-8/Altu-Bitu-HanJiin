#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MIN = 3000;

// 좌표를 구하는 식이 복잡해져서 아래 블로그 글을 참고했습니다. 
// https://yaneodoo2.tistory.com/entry/CC-%EB%A7%B5%EC%A2%8C%ED%91%9C-%EB%8F%99%EC%84%9C%EB%82%A8%EB%B6%81-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%AC%B8%EC%A0%9C-%EA%B3%A0%EC%B0%B0
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

// 꽃을 심을 수 있는지 확인하는 함수
bool isAvailable(vector< vector<bool> > &available, int x, int y, int n){
    for(int i = 0; i < 5; i++){
        // 참고한 부분
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx > n - 1 || ny > n - 1){
            return false;
        }
        if(available[nx][ny] == false){
            return false;
        }
    }
    return true;
}


//꽃의 가격을 구하는 함수
int getPrice(vector< vector<int> > &arr, int x, int y){
    int price = 0;
    for(int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        price += arr[nx][ny];
    }
    return price;
}

// 심을 수 있는 지 없는 지 상태를 바꾸는 함수
void canPlant(int x, int y, vector< vector<bool> > &available, bool flag){
    for(int i = 0; i < 5; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        available[nx][ny] = flag;
    }
}
//최소 비용 구하는 함수
int getMinPrice(int n, vector< pair<int, int> > &dot, vector< vector<int> > &arr){
    int result = MIN;
    int size = dot.size();
    vector< vector<bool> > available(n, vector<bool>(n, true));
    for(int i = 0; i < size; i++){
        int x1 = dot[i].first;
        int y1 = dot[i].second;
        // 심을 수 없으면 넘어감
        if(!isAvailable(available, x1, y1, n)){
            continue;
        }
        // 가격 구하기
        int price1 = getPrice(arr, x1, y1);
        canPlant(x1, y1, available, false);

        for(int j = i + 1; j < size; j++){
            int x2 = dot[j].first;
            int y2 = dot[j].second;
            if(!isAvailable(available, x2, y2, n)){
            continue;
            }
            int price2 = getPrice(arr, x2, y2);
            canPlant(x2, y2, available, false);

            for(int k = j + 1; k < size; k++){
                int x3 = dot[k].first;
                int y3 = dot[k].second;
                if(!isAvailable(available, x3, y3, n)){
                    continue;
                }
                int price3 = getPrice(arr, x3, y3);
                canPlant(x3, y3, available, false);

                int sum = (price1 + price2 + price3);
                result = min(sum, result);
                canPlant(x3, y3, available, true);
            }
            canPlant(x2, y2, available, true);
        }
        canPlant(x1, y1, available, true);
    }
    return result;
}


int main(){
    int n;
    cin >> n;

    //화단 가격 입력 받기 & 좌표 저장하기
    vector< vector<int> > arr(n, vector<int>(n));
    vector< pair<int, int> > dot;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            dot.push_back(make_pair(i, j));
        }
    }
    cout << getMinPrice(n, dot, arr) << "\n";


    return 0;
}