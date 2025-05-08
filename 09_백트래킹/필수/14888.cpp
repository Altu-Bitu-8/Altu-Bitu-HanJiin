#include <iostream>
#include <vector>

using namespace std;

int min_result = 1000000000;
int max_result = -1000000000;

void backtracking(int n, int index, int curr, int plus, int minus, int multi, int div, vector<int> &arr){
    
    if(index == n){
        if(curr > max_result){
            max_result = curr;
        }
        if(curr < min_result){
            min_result = curr;
        }
        return;
    }
    if (plus > 0)
        backtracking(n, index + 1, curr + arr[index], plus - 1, minus, multi, div, arr);
    if (minus > 0)
        backtracking(n, index + 1, curr - arr[index], plus, minus - 1, multi, div, arr);
    if (multi > 0)
        backtracking(n, index + 1, curr * arr[index], plus, minus, multi - 1, div, arr);
    if (div > 0)
        backtracking(n, index + 1, curr / arr[index], plus, minus, multi, div - 1, arr);

}

int main(){
    int n, plus, minus, multi, div;
    
    cin >> n;

    vector<int> arr(n+1, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> plus >> minus >> multi >> div;

    backtracking(n, 1, arr[0], plus, minus, multi, div, arr);
    cout << max_result << "\n";
    cout << min_result << "\n";
}