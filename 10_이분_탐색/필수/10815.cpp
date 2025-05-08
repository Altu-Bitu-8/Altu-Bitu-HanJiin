#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int key, vector<int> &arr){
    int left = 0;
    int right = n - 1;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;
        if(arr[mid] == key){
            return 1;
        }
        // 찾는 값이 중간값보다 왼쪽에 있을 때
        else if(arr[mid] > key){
            right = mid - 1;
        }
        // 찾는 값이 중간값보다 오른쪽에 있을 때
        else{
            left = mid + 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, key;
    
    // 입력
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    cin >> m;
    while(m--){
        cin >> key;
        // 연산 & 출력
        cout << binarySearch(n, key, arr) << " ";
    }
    cout << '\n';
    return 0;
}