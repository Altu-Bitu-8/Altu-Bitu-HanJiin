#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> pii;

const int MAX = 200000;

int getLongest(int n, int k, vector<int> &arr){
  vector<int> count(MAX + 1, 0);
  int length = 0, left = 0, right = 0;
  int max_length = 0;
  // 첫 번째 수 추가
  count[arr[left]]++;

  while((left <= right) && (right < n - 1)){
    int next_right = right + 1;
    // 다음 right을 추가할 수 있다면 right 이동시키고 추가
    if(count[arr[next_right]] < k){
      // cout << count[arr[next_right]] << endl;
      count[arr[next_right]]++;
      right++;
    }
    // left와 right가 같다면 둘 다 증가시킴
    else if(left == right){
      left++;
      right++;
    }
    // 그렇지 않으면 left 오른쪽으로 이동시킴
    else{
      count[arr[left]]--;
      left++;
    }
    length = right - left + 1;
    if(max_length < length){
      max_length = length;
    }
  }
  return max_length;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  // 입력
  int n, k;
  cin >> n >> k;

  vector<int> arr(n, 0);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  // 연산 및 출력
  cout << getLongest(n, k, arr) << "\n";
  return 0;
}