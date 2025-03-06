#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

const int MAX = 1000000;

using namespace std;

vector<int> getPrime(vector<bool> &is_prime) {
    vector<int> primes;

    for(int i = 2; i <= sqrt(MAX); i++){
        if(!is_prime[i]){
            continue;
        }
        primes.push_back(i);
        for(int j = i * i; j <= MAX; j += i){
            if(!is_prime[j]) continue;
            is_prime[j] = false;
        }
    }
    return primes;
}

void findGoldbach(int n, vector<bool> &is_prime){
    for(int i = 3; i <= n; i++){
        if(is_prime[i] && (is_prime[n - i])){
            cout << n << " = " << i << " + " << n - i << "\n";
            return;
        }
    }
    cout << "Goldbach's conjecture is wrong.\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    vector<bool> is_prime(MAX + 1, true);
    getPrime(is_prime);

    while(true){
        cin >> n;
        if(n == 0) break;

        findGoldbach(n, is_prime);
    }

    return 0;
}
