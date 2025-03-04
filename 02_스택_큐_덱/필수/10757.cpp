#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void insertZero(deque <int> &a, deque<int> &b){
    int size1 = a.size();
    int size2 = b.size();

    int diff = size1 - size2;
    
    while(diff--){
        b.push_front(0);
    }
}
void calculate(deque <int> &a, deque<int> &b){
    int size = a.size();
    int carry = 0;
    deque<int> result;
    
    for(int i = size - 1; i >= 0; i--){
        int sum = a[i] + b[i] + carry;
        result.push_front(sum % 10);
        carry = sum / 10;
    }

    if(carry == 1){
        result.push_front(carry);
    }

    for(int digit : result){
        cout << digit;
    }
}

int main(){
    deque<int> a, b;
    string s1, s2;

    cin >> s1 >> s2;
    
    for(char ch : s1){
        a.push_back(ch - '0');
    }
    for(char ch : s2){
        b.push_back(ch - '0');
    }

    if (b.size() > a.size()) {
        swap(a, b);
    }
    
    insertZero(a, b);
    calculate(a, b);

    return 0;
}