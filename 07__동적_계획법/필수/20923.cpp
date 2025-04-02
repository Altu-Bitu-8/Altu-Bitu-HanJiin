#include <iostream>
#include <deque>

using namespace std;

void ringBell(deque<int> &dodo, deque<int> &su, int round){
    // m번 진행한 후 자신의 덱에 더 많은 카드를 지닌 사람이 승리한다.
    // m번 진행 후 각자의 덱에 있는 카드의 개수가 같다면 비긴 것으로 본다.
    if(dodo.size() > su.size()){
        cout << "do\n";
    }
    else if(dodo.size() < su.size()){
        cout << "su\n";
    }
    else{
        cout << "dosu\n";
    }
}

void halliGalli(deque<int> &dodo, deque<int> &su, int n, int m){
    deque<int> do_ground;
    deque<int> su_ground;
    int round = 0;

    while(true){
        int sum = 0;
        do_ground.push_back(dodo.front());
        dodo.pop_front();
        if(dodo.empty()){
            cout << "su\n";
            break;
        }
        // 카드 합이 5가 된다 - 수연 종 침(한 쪽 그라운드 비어있는 경우 x)
        if(!do_ground.empty() && !su_ground.empty() && (do_ground.back() + su_ground.back() == 5)){
            while(!do_ground.empty()){
                su.push_back(do_ground.front());
                do_ground.pop_front();
            }
            while(!su_ground.empty()){
                su.push_back(su_ground.front());
                su_ground.pop_front();
            }
            // 도도의 덱이 0이 되면 수연 승리
            if(dodo.empty()){
                cout << "su\n";
                break;
            }
        }
        // 5가 나온다 - 도도 종 침
        else if(!do_ground.empty()&&do_ground.back() == 5){
            while(!su_ground.empty()){
                dodo.push_back(su_ground.front());
                su_ground.pop_front();
            }
            while(!do_ground.empty()){
                dodo.push_back(do_ground.front());
                do_ground.pop_front();
            }
            // 수연의 덱이 0이 되면 도도 승리
            if(su.empty()){
                cout << "do\n";
                break;
            }
        }
        round++;
        if(round == m){
            ringBell(dodo, su, round);
            break;
        }

        su_ground.push_back(su.front());
        su.pop_front();
        if(su.empty()){
            cout << "do\n";
            break;
        }
        // 카드 합이 5가 된다 - 수연 종 침(한 쪽 그라운드 비어있는 경우 x)
        if(!do_ground.empty() && !su_ground.empty() && (do_ground.back() + su_ground.back() == 5)){
            while(!do_ground.empty()){
                su.push_back(do_ground.front());
                do_ground.pop_front();
            }
            while(!su_ground.empty()){
                su.push_back(su_ground.front());
                su_ground.pop_front();
            }
            // 도도의 덱이 0이 되면 수연 승리
            if(dodo.empty()){
                cout << "su\n";
                break;
            }
        }
        // 5가 나온다 - 도도 종 침
        else if(!su_ground.empty() && su_ground.back() == 5){
            while(!su_ground.empty()){
                dodo.push_back(su_ground.front());
                su_ground.pop_front();
            }
            while(!do_ground.empty()){
                dodo.push_back(do_ground.front());
                do_ground.pop_front();
            }
            // 수연의 덱이 0이 되면 도도 승리
            if(su.empty()){
                cout << "do\n";
                break;
            }
        }
        round++;
        if(round == m){
            ringBell(dodo, su, round);
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, num1, num2;

    deque<int> dodo;
    deque<int> su;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> num1 >> num2;
        dodo.push_front(num1);
        su.push_front(num2);
    }

    halliGalli(dodo, su, n, m);
    return 0;
}