#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    vector<ll> speed(n, 0);
    for (ll i = 0; i < n; i++){
        cin >> speed[i];
    }

    ll result = speed[n - 1];
    // 끝에서 부터 이전 수보다 크면서 현재수의 배수 구하기
    for (int i = n - 2; i >= 0; i--){
        if (speed[i] >= result){
            result = speed[i];
        }
        else{
            if (result % speed[i]){
                ll temp = speed[i] - (result % speed[i]);
                result += temp;
            }
        }
    }
    cout << result;

    return 0;
}