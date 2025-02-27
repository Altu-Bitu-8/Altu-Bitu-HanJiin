#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void calcNge(int &n, vector<int> &arr, vector<int> &nge, stack<int> &s){
    for(int i = 0; i < n; i++){
        cin >> arr[i];

    }
    
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            nge[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i = 0; i < n; i++){
        cout << nge[i] << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cin.tie(NULL);

    int n, a;
    cin >> n;

    vector<int> arr(n), nge(n, -1);
    stack<int> s;
    
    calcNge(n, arr, nge, s);
    
    return 0;
}