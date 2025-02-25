#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertZero(vector <int> &a, vector<int> &b){
    int size1 = a.size();
    int size2 = b.size();
    
    if(size1 > size2){
        for(int i = 0; i < size1 - size2; i++)
            b.insert(b.begin(), 0);
    }
    if(size2 > size1){
        for(int i = 0; i < size2 - size1; i++)
            a.insert(a.begin(), 0);
    }
}
void calculate(vector <int> &a, vector<int> &b){
    int size = a.size();
    int sum = 0;
    vector<int> result(size+1);
    
    int carry = 0;
    for(int i = size - 1; i >= 0; i--){
        sum = (a[i] + b[i] + carry) % 10;
        carry = (a[i] + b[i] + carry) / 10;
        result[size - 1 - i] = sum;
    }

    if(carry == 1){
        result[size] = carry;
    } else {
        result.pop_back();
    }

    for(auto iter = result.rbegin(); iter != result.rend(); iter++){
        cout << *iter;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> a, b;
    string s1, s2;

    cin >> s1 >> s2;
    
    for(char ch : s1){
        a.push_back(ch - '0');
    }
    for(char ch : s2){
        b.push_back(ch - '0');
    }
    
    insertZero(a, b);
    calculate(a, b);

    return 0;
}