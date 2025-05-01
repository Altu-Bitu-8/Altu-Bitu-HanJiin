#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, len;
    int max_len = 0;

    int a[1001], dp[1001];

    cin >> n;
    
    //연산
    for(int i = 0; i < n; i++){
        cin >> a[i];
        len = 0;

        for(int j = 0; j < i; j++){
            if(a[i] > a[j]){
                len = max(dp[j], len);
            }
        }
        dp[i] = len + 1;

        max_len = max(dp[i], max_len);
    }

    cout << max_len << "\n";

    return 0;
}