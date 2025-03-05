#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getGcd(int a, int b){
    while(b != 0){
        a %= b;
        swap(a, b);
    }
    return a;
}

int main(){
    int n, s;
    int result = 0;

    cin >> n >> s;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        arr[i] = abs(arr[i] - s);
    }

    for(int i = 0; i < n; i++){
        result = getGcd(result, arr[i]);
    }

    cout << result;
        
    return 0;
}