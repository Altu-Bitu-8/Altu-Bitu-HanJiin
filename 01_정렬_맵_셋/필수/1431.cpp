#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numSum(const string &s){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        char c = s[i];
        if(isdigit(c)){
            sum += c - '0';
        }
    }
    return sum;
}

bool cmp(const string &a, const string &b){
    if (a.size() != b.size()){
        return a.size() < b.size();
    }
    if (numSum(a) != numSum(b)){
        return numSum(a) < numSum(b);
    }
    return a < b;
}

int main(){

    int n;
    cin >> n;
    vector<string> input(n);

    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    sort(input.begin(), input.end(), cmp);

    for(int i = 0; i < input.size(); i++){
        cout << input[i] << '\n';
    }

    return 0;
}