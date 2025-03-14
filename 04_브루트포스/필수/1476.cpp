#include <iostream>

using namespace std;

const int MAX = 7980;

int getYear(int e, int s, int m){
    for(int i = 1; i <= MAX; i++){
        bool new_e = (i % 15 == e);
        if(e == 15) new_e = (i % 15 == 0);

        bool new_s = (i % 28 == s);
        if(s == 28) new_s = (i % 28 == 0);

        bool new_m = (i % 19 == m);
        if(m == 19) new_m = (i % 19 == 0);

        if(new_e && new_s && new_m){
            return i;
        }
    }
    return 0;
}
int main(){
    // 입력
    int e, s, m;
    cin >> e >> s >> m;

    //연산
    int year = getYear(e, s, m);

    //출력
    cout << year << "\n";
    return 0;
}