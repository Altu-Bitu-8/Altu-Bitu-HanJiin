#include <iostream>

using namespace std;

int calcSet(int set, string calc){
    int new_set = 0;
    int num;
    if(calc == "add"){
        cin >> num;
        if(!(set & (1 << num))){
            set |= (1 << num);
        }
    }
    else if(calc == "remove"){
        cin >> num;
        if(set & (1 << num)){
            set &= ~(1 << num);
        }
    }
    else if(calc == "check"){
        cin >> num;
        if(set & (1 << num)) cout << "1\n";
        else cout << "0\n";
    }
    else if(calc == "toggle"){
        cin >> num;
        set ^= (1 << num);
    }
    else if(calc == "all"){
        new_set = (1 << 21) - 2;
        set = new_set;
    }
    else if(calc == "empty"){
        set = 0;
    }
    return set;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int s,  num;
    string calc;
    cin >> s;
    int set = 0;

    while(s--){
        cin >> calc;
        set = calcSet(set, calc);
    }
    return 0;
}