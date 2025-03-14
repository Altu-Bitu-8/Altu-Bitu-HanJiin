#include <iostream>

using namespace std;

const int MAX = 10000000;
const int INDEX = 0;

int getBottle(int n, int k){
    for(int i = 0; i < MAX; i++){
        int bottle = n + i;
        int cnt = 0;
        while(bottle > 0){
            // 2의 거듭제곱의 개수 세기
            if(bottle & (1 << INDEX)){
                cnt++;
            }
            // 오른쪽으로 한 칸 밀기
            bottle /= 2;
        }
        if(cnt <= k){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, k;
    cin >> n >> k;
    cout << getBottle(n, k) << "\n";
    return 0;
}