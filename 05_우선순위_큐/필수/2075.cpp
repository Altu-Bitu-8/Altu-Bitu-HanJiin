#include <iostream>
#include <queue>

using namespace std;

int getN(int n, priority_queue<int, vector<int>, greater<int> > &pq){
    int num;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> num;
            // 힙의 크기를 n으로 유지
            if(pq.size() < n){
                pq.push(num);
            }
            // 힙이 다 찼을 때, 새로 들어오는 숫자가 가장 작은 숫자보다 크면 작은 숫자 제거, 새로운 숫자 push
            if(pq.size() == n && num > pq.top()){
                pq.pop();
                pq.push(num);
            }
        }
    }
    return pq.top();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    // 오름차순
    priority_queue<int, vector<int>, greater<int> > pq;

    // 입력
    cin >> n;

    // 연산
    int result = getN(n, pq);

    // 출력
    cout << result;
    return 0;
}