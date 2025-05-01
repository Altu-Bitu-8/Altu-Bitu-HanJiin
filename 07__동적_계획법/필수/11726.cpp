#include <iostream>

using namespace std;

int main(){
    int n;
    int dp[1001];
    
    // 입력
    cin >> n;

    // 연산
    for(int i = 1; i <= n; i++){
        if(i <= 2){
            dp[i] = i;
        } else{
            dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
        }
    }

    // 출력
    cout << dp[n] << "\n";

    return 0;
}