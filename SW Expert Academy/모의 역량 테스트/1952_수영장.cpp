// Created by 길민호 on 2022/11/05.
#include <bits/stdc++.h>
using namespace std;

int plan[13];
int minCost;
int dayCost, oneMonthCost, threeMonthCost, yearCost;

void back(int curMonth, int curCost){
    if(curMonth > 12){
        minCost = min(minCost, curCost);
    }else{
        if(plan[curMonth] == 0){
            back(curMonth + 1, curCost);
        }else{
            // 현재 월에 모두 1일 이용권을 사용하는 경우
            // 현재 월에 1달 이용권을 사용하는 경우
            // 현재 월에 3달 이용권을 사용하는 경우

            int dc[3] = {plan[curMonth] * dayCost, oneMonthCost, threeMonthCost};
            int dm[3] = {1, 1, 3};

            for(int i = 0; i < 3; i++){
                back(curMonth + dm[i], curCost + dc[i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){

        cin >> dayCost >>  oneMonthCost >> threeMonthCost >> yearCost;

        int totalUseDay = 0;
        for(int i = 1; i <= 12; i++) {
            cin >> plan[i];
            totalUseDay += plan[i];
        }

        if(totalUseDay != 0){
            minCost = yearCost;
            back(1, 0);
        }

        cout << "#" << tc << " " << "\n";
    }
}