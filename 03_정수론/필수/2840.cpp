#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void getWheel(int n, int k){
    int chg;
    int now = n - 1;
    char alphabet;
    vector<char> wheel(n, '?');
    while(k--){
        cin >> chg >> alphabet;
        now -= chg;
        if(now < 0){
            while(now < 0){
                now += n;
            }
        }
        if(wheel[now] != '?' && wheel[now] != alphabet){
            cout << "!";
            return;
        }
        wheel[now] = alphabet;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if((wheel[i] == wheel[j]) && (wheel[i] != '?')){
                cout << "!";
                return;
            }
        }
    }

    for(int i = now; i < n; i++){
        cout << wheel[i];
    }
    for(int i = 0; i < now; i++){
        cout << wheel[i];
    }
}

int main(){
    int n, k;
    cin >> n >> k;

    getWheel(n, k);
    return 0;
}