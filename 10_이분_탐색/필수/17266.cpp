#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//가로등의 길이가 k일 때 상근이가 건널 수 있는 지 확인
bool canPass(int n, int k, vector<int> &light){
    if((light[0] - k) > 0){
        return false;
    }
    for(int i = 1; i < light.size(); i++){
        if(light[i] - k > light[i - 1] + k){
            return false;
        }
    }
    if(light.back() + k < n){
        return false;
    }
    return true;
}

int binarySearch(int n, vector<int> &light){
    int left = 1;
    int right = n;
    int mid;
    
    while(left <= right){
        mid = (left + right) / 2;
        // k 길이로 통과할 수 있다면 더 짧은 길이로 가능한 지 체크
        if(canPass(n, mid, light)){
            right = mid - 1;
        }
        // 통과할 수 없다면 길이 늘리기
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;

    cin >> n >> m;
    vector<int> light(m, 0);
    for(int i = 0; i < m; i++){
        cin >> light[i];
    }

    sort(light.begin(), light.end());

    cout << binarySearch(n, light) << '\n';

    return 0;
}