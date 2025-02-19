#include <iostream>
#include <cmath>

using namespace std;

int main(){
    // 체중, 다이어트 전과 후 에너지 섭취량, 다이어트 전과 후 기초 대사량, 다이어트 기간, 기초 대사량 변화 역치
    int weight, csm_before, csm_after, bmr, day, t;
    // 일일 활동 대사량
    int activity = 0;
    
    cin >> weight >> csm_before >> t;
    bmr = csm_before;

    cin >> day >> csm_after >> activity;

    // 기초 대사량이 변하지 않을 때 체중 변화
    int csmp = bmr + activity;
    int weight_after = weight;

    for(int i = 1; i <= day; i++){
        weight_after += (csm_after - csmp);
    }
    if (weight_after <= 0) {
            cout << "Danger Diet" << "\n";
    }else{
        cout << weight_after << ' ' << bmr << '\n';
    }

    // 기초 대사량이 변할 때 체중 변화
    for(int i = 1; i <= day; i++){
        int csmp_bmr = bmr + activity;
        weight += (csm_after - csmp_bmr);

        if(abs(csm_after - csmp_bmr) > t){
            bmr += floor((csm_after - csmp_bmr)/2.0);
        }
    }
    if (weight <= 0 || bmr <= 0) {
            cout << "Danger Diet" << "\n";
    }else{
        cout << weight<< ' ' << bmr << ' ';
        if(csm_before - bmr)
            cout << "YOYO" << '\n';
        else 
            cout << "NO" << '\n';
    }

    return 0;
}