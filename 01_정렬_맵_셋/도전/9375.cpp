#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct closet{
    string name, type;
};

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string type, name;

        map <string, set<string> > my_closet;
        for(int i = 0; i < n; i++){
            cin >> name >> type;
            my_closet[type].insert(name);
        }
        int count = 0;
        int result = 1;

        for (auto& iter : my_closet) {
            count = iter.second.size();
            result *= (count + 1);
        }

        result -= 1;
        cout << result << endl;
    }
    return 0;
}