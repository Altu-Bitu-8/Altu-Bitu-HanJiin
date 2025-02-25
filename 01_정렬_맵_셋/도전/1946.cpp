#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct grade {
    int a, b;
};

bool comp(const grade &g1, const grade &g2){
    return g1.a < g2.a;
}

int main(){
    int t;
    cin >> t;

    int n;
	
    while (t--) {
        cin >> n;
        vector<grade> result(n);
        int count = 1;
        for(int i = 0; i < n; i++){
            cin >> result[i].a >> result[i].b;
        }

        sort(result.begin(), result.end(), comp);
        int min_b = result[0].b;

        for(int i = 1; i < n; i++){
            if(result[i].b < min_b){
                min_b = result[i].b;
                count++;
            }
        }
        cout<< count<< "\n";
    }

    return 0;
}