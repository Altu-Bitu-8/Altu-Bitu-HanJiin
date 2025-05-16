#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cntPlate(vector<int> &arr, int n, int d, int k){
  vector<int> eaten(d + 1, 0);
  int count = 1; // 쿠폰 이용했으므로 1부터 시작

  for(int i = 0; i < k; i++){
    // 쿠폰으로 먹은 초밥이 아니고 새로 먹는 종류라면 카운트 증가
    if((arr[i] != 0) && (eaten[arr[i]] == 0)){
      count++;
    }
    // 종류 카운트 증가
    eaten[arr[i]]++;
  }
  int max_count = count;
  for(int i = 0; i < n - 1; i++){
    // 종류 카운트 감소
    eaten[arr[i]]--;
    // 만약에 빠진 숫자가 더 이상 벡터에 존재하지 않는다면 카운트를 감소시킨다
    if(eaten[arr[i]] == 0 && arr[i] != 0){
      count--;
    }
    // 종류 카운트 증가
    eaten[arr[(i + k) % n]]++;
    // 만약에 새로 추가하는 숫자가 처음으로 추가되는 숫자라면 카운트를 증가시킨다
    if(eaten[arr[(i + k) % n]] == 1 && arr[(i + k) % n] != 0){
      count++;
    }
    // 최댓값 갱신
    if(max_count < count){
      max_count = count;
    }
  }
  return max_count;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // 입력
  int n, d, k, c;
  cin >> n >> d >> k >> c;

  vector<int> arr(n, 0);

  for(int i = 0; i < n; i++){
    cin >> arr[i];
    // 쿠폰 이용
    if(arr[i] == c){
      arr[i] = 0;
    }
  }

  cout << cntPlate(arr, n, d, k) << "\n";

  return 0;
}