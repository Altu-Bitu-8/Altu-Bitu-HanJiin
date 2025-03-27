#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct worker{
    int d, h, line, order;
};

//힙은 어떻게 정렬하는가? 1. Di가 큰 순, 2. Hi가 큰 순, 3. 줄 번호가 낮은 순
struct cmp{
    bool operator()(worker a, worker b){
        if(a.d != b.d){
            return a.d < b.d;
        }
        if(a.h != b.h){
            return a.h < b.h;
        }
        return a.line > b.line;
    }
};

int count(int n,int m, int k, priority_queue<worker, vector<worker>, cmp> &pq){
    int cnt = 0;
    vector<worker> my_worker(n);
    //각 줄 마다 큐를 저장해줌
    vector<queue<worker> > line(m);
    for(int i = 0; i < n; i++){
        int line_number = i % m;
        cin >> my_worker[i].d >> my_worker[i].h;
        my_worker[i].order = i;
        my_worker[i].line = line_number;
        line[line_number].push(my_worker[i]);
    }
    // 줄보다 사람 수가 적으면 사람 수 만큼만 반복
    if(m > n){
        for(int i = 0; i < n; i++){
            pq.push(line[i].front());
            line[i].pop();
        }
    }else{
        for(int i = 0; i < m; i++){
            pq.push(line[i].front());
            line[i].pop();
        }
    }

    while(!pq.empty()){
        worker now = pq.top();
        pq.pop();
        // 데카 차례가 오면 return
        if(now.order == k){
            return cnt;
        }
        // 사람 수 세어 줌
        cnt++;
        // 같은 라인에 사람이 있다면 푸시해줌
        if(!line[now.line].empty()){
            pq.push(line[now.line].front());
            line[now.line].pop();
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    priority_queue<worker, vector<worker>, cmp> pq;

    // 입력
    cin >> n >> m >> k;

    // 연산
    int result = count(n, m, k, pq);

    // 출력
    cout << result;
    return 0;
}