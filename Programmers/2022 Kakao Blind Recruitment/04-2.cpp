// Created by 길민호 on 2022/09/04.

#include <bits/stdc++.h>
using namespace std;

vector<int> targetCnt(11);
vector<int> answer(11);
int maxScoreDiff = INT_MIN;
int N;

// 중복 조합
// cnt는 남은 화살 개수
// target은 현재 맞출 과녁의 점수
// scoreDiff는 라이언 점수 - 어피치의 점수
void back(int target, int cnt, int scoreDiff, vector<int> & info){
    if(target == 11){
        if(cnt == 0 && scoreDiff > 0){
            bool swap = false;
            if(scoreDiff > maxScoreDiff) swap = true;
            // 같은 점수차인 경우, 낮은 점수를 더 많이 맞힌 경우 swap
            if(scoreDiff == maxScoreDiff){
                for(int t = 10; t >= 0; t++){
                    if(targetCnt[t] > answer[t]){
                        swap = true; break;
                    }else if(targetCnt[t] < info[t]){
                        break;
                    }
                }
            }

            // 더 큰 점수차로 라이언이 이기거나, 같은 점수차인데, 낮은 점수를 더 많이 맞힌 경우 swap
            if(swap){
                maxScoreDiff = scoreDiff;
                copy(targetCnt.begin(), targetCnt.end(), answer.begin());
            }
        }
    }else{
        int apeachCnt = info[target];   // 어피치가 target 점수를 맞춘 횟수

        // target 점수를 0번 부터, min(어피치가 target을 맞춘 횟수 + 1, cnt)까지 맞춰봄
        for(int c = 0; c <= min(apeachCnt + 1, cnt); c++){
            int tmpScoreDiff = scoreDiff;

            // 라이언과 어피치가 맞춘 횟수가 같으면 둘 다 점수를 획득하지 못함
            // 라이언의 횟수가 더 많으면 라이언이 점수 획득
            // 어피치의 횟수가 더 많거나 같으면 어피치가 점수 획득
            if(!(c == 0 && apeachCnt == 0)){
                if(c <= apeachCnt) tmpScoreDiff -= target;
                else if(c > apeachCnt) tmpScoreDiff += target;
            }

            targetCnt[target] = c;
            back(target + 1, cnt - c, tmpScoreDiff, info);
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    reverse(info.begin(), info.end());

    back(0, n, 0, info);

    reverse(answer.begin(), answer.end());
    if(maxScoreDiff == INT_MIN) return {-1};
    else return answer;
}