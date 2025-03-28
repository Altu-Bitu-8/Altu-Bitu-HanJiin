#include <iostream>
#include <vector>

using namespace std;

int countAte(vector<int> &table, int k)
{
    int cnt = 0;

    for (int i = 0; i < table.size(); i++){
        // 배열을 돌며 햄버거인 경우와 이미 햄버거를 먹어버린 경우 continue
        if (table[i] == 1 || table[i] == 0){
            continue;
        }
        // table의 값이 -1인 경우(인간인 경우)
        // 앞이나 뒤에 햄버거 있으면 인간++, 햄버거--
        for (int j = k; j >= 1; j--){
            if (i - j >= 0 && table[i - j] == 1){
                table[i]++;
                table[i - j]--;
                // 햄버거가 배정되는 경우 cnt++
                cnt++;
                break;
            }
        }

        if (table[i] == -1){
            for (int p = 1; p <= k; p++){
                if (i + p < table.size() && table[i + p] == 1){
                    table[i]++;
                    table[i + p]--;
                    // 햄버거가 배정되는 경우 cnt++
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int n, k;
    string s;

    // 입력
    cin >> n >> k;
    cin >> s;

    vector<int> table(n, 0);
    // 인간이면 -1, 햄버거면 1로 배열에 저장함
    for (int i = 0; i < n; i++){
        if (s[i] == 'H'){
            table[i] = 1;
        }
        else{
            table[i] = -1;
        }
    }

    // 계산
    int result = countAte(table, k);

    // 출력
    cout << result;

    return 0;
}