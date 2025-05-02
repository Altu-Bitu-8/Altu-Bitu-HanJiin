#include <iostream>
#include <vector>

using namespace std;
const int MAX_NUM = 10000000;

int backtracking(int n, int weight, int idx, int cur, vector<vector<int> > &w, vector<bool> &is_used, int start){
    if(idx == n){
        // 시작 도시로 돌아올 수 있는 경우에만
        if(w[cur][start] == 0){
            return MAX_NUM;
        }
        // 돌아가는 비용 추가하기
        return weight + w[cur][start];
    }

    int min_cost = MAX_NUM;
    int temp;

    for(int i = 0; i < n; i++){
        if(is_used[i]){
            continue;
        }
        
        if(w[cur][i] == 0){
            continue;
        }

        is_used[i] = true;
        temp = backtracking(n, weight + w[cur][i], idx + 1, i, w, is_used, start);
        min_cost = min(temp, min_cost);
        is_used[i] = false;
    }
    
    
    return min_cost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<vector<int> > w(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w[i][j];
        }
    }

    vector<bool> is_used(n, false);
    int start = 0;
    is_used[start] = true;
    int result = backtracking(n, 0, 1, start, w, is_used, start);
    
    // 출력
    cout << result << "\n";
}