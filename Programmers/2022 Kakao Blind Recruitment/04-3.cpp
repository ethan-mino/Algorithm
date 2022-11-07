// Created by SSAFY on 2022-11-07.

#include <bits/stdc++.h>
using namespace std;

int maxDiff = INT_MIN;

int judge(int lionHit, int apeachHit){
    int win;    // 1 : 라이언이 점수 획득, 0 : 어피치가 점수 획득, -1 : 모두 획득할 수 없음
    if(apeachHit < lionHit){ // 라이언이 더 많이 맞힌 경우
        win = 1;
    }else if (apeachHit > lionHit){  // 어피치가 더 많이 맞춘 경우
        win = 0;
    }else if(apeachHit == lionHit){  // 맞힌 화살의 개수가 같은 경우
        if(apeachHit != 0){
            win = 0;
        }else{  // 모두 0발을 맞힌 경우
            win = -1;
        }
    }

    return win;
}

vector<int> lionHitCnts(11);
vector<int> tempHitCnts(11);

void back(int targetScore, int remainArrow, vector<int> apeachHitCnts, int lionScore, int apeachScore){
    if(targetScore == 11){
        if(remainArrow != 0) return;

        int diff = lionScore - apeachScore;
        bool swap = false;

        if(diff > 0) {
            if(maxDiff < diff){
                maxDiff = diff;
                copy(tempHitCnts.begin(), tempHitCnts.end(), lionHitCnts.begin());
            }
        }
    }else{
        // 한 발도 안 맞추거나, 어피치보다 1 크게 맞추거나
        vector<int> lionHitCnts;

        for(int i = min(remainArrow, apeachHitCnts[targetScore] + 1); i >= 0; i--)
            lionHitCnts.push_back(i);

        for(auto lionHitCnt : lionHitCnts){
            int apeachHitCnt = apeachHitCnts[targetScore];
            int nxLionScore = lionScore, nxApeachScore = apeachScore;
            // 1 : 라이언이 점수 획득, 0 : 어피치가 점수 획득, -1 : 모두 획득할 수 없음
            int win = judge(lionHitCnt, apeachHitCnt);

            if(win == 1) nxLionScore += targetScore;    // 라이언이 이긴 경우
            else if(win == 0) nxApeachScore += targetScore; // 어피치가 이긴 경우

            int nxRemainArrow = remainArrow - lionHitCnt;
            tempHitCnts[targetScore] = lionHitCnt;
            back(targetScore + 1, nxRemainArrow, apeachHitCnts, nxLionScore, nxApeachScore);
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    // 어피치가 0점을 맞힌 화살 개수 ~ 10점을 맞힌 화살 개수
    reverse(info.begin(), info.end());

    back(0, n, info, 0, 0);

    cout << maxDiff << "\n";
    reverse(lionHitCnts.begin(), lionHitCnts.end());

    if(maxDiff == INT_MIN) return {-1} ;
    else return lionHitCnts;
}