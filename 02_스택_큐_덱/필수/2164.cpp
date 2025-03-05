#include <iostream>
#include <deque>

using namespace std;

int result(deque<int> &d){
    int size = d.size();
    for(int i = 0; i < size - 2; i++){
        d.pop_front();
        d.push_back(d.front());
        d.pop_front();
    }
    d.pop_front();
    return d.front();
}

int main(){
    int n;
    deque<int> d;
    cin >> n;
    for(int i = 1; i <= n; i++){
        d.push_back(i);
    }
    
    if(n == 1 || n == 2){
        cout << n << '\n';
    }
    else{
        cout << result(d) << '\n';
    }
    
    return 0;
}