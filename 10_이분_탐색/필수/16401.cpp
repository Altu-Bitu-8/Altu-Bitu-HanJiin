#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 과자 길이가 k일 때 조카 몇 명을 나눠줄 수 있는가?
int cntNephew(int k, vector<int> &snack){
    int count = 0;
    for(int i = 0; i < snack.size(); i++){
        count += snack[i] / k;
    }
    return count;
}

int binarySearch(int n, int target, vector<int> &snack){
    int left = 1;
    int right = snack[n - 1];
    int mid;

    while(left <= right){
        mid = (left + right) / 2;
        int nephew = cntNephew(mid, snack);
        // mid 길이로 더 많은 조카를 나눠줄 수 있다면 길이를 늘린다
        if(nephew >= target){
            left = mid + 1;
        }
        // mid 길이로 조카 수 만큼 나눠줄 수 없다면 길이를 줄인다
        else{
            right = mid - 1;
        }
    }
    // 조카에게 과자를 나눠줄 수 없을 때
    if(right < 1){
        return 0;
    }
    // upper bound : left - 1
    else{
        return left - 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;

    vector<int> snack(n, 0);
    for(int i = 0; i < n; i++){
        cin >> snack[i];
    }

    sort(snack.begin(), snack.end());

    cout << binarySearch(n, m, snack) << '\n';
    return 0;
}