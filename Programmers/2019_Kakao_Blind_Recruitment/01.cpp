// Created by 길민호 on 2022/10/13.

#include <bits/stdc++.h>

using namespace std;

#define FAIL_RATE first
#define STAGE second

int challengingStage[510];
int prefixSum[510];

bool cmp(pair<double, int> info1, pair<double, int> info2){
    if(info1.FAIL_RATE == info2.FAIL_RATE){
        return info1.STAGE < info2.STAGE;
    }else return info1.FAIL_RATE > info2.FAIL_RATE;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> failRates;

    for(auto stage : stages){
        // 유저들이 현재 도전중인 스테이지를 기록
        challengingStage[stage]++;
    }

    prefixSum[N + 1] = challengingStage[N + 1];
    for(int i = N; i >= 1; i--){
        // 스테이지의 누적 클리어 수
        // 해당 스테이지에 도달한 유저의 수
        // i번째 스테이지에 도달한 유저 수 = i번째 스테이지를 도전 중인 유저의 수 + i + 1번째 이상 스테이지에 도달한 유저의 수
        prefixSum[i] = challengingStage[i] + prefixSum[i + 1];
    }

    for(int stage = 1; stage <= N; stage++){
        double failRate;
        if(prefixSum[stage] == 0) failRate = 0;
        else failRate = (double) challengingStage[stage] / prefixSum[stage];
        failRates.push_back({failRate, stage});
    }

    sort(failRates.begin(), failRates.end(), cmp);

    for(auto failRate : failRates){
        answer.push_back(failRate.second);
    }
    return answer;
}
