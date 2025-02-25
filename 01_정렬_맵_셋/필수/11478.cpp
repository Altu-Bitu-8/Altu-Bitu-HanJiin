#include <iostream>
#include <set>
#include <string>

using namespace std;

int countString(const string &s, set<string> &result){
    int len = s.size();
    int count = 0;
    for(int i = 0; i < len; i++){
        for(int j = 1; j <= len - i; j++){
            result.insert(s.substr(i, j));
        }
    }
    for(auto iter : result){
        count++;
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    string s;
    cin >> s;

    set<string> result;

    int count = 0;

    count = countString(s, result);
    cout << count << '\n';
    
    return 0;
}

