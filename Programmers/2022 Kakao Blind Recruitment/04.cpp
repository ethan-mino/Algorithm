// Created by 길민호 on 2022/09/04.
#include <bits/stdc++.h>
using namespace std;

int diff = INT_MIN; // 어피치와의 점수 차
bool win = false;
vector<int> result(11);
vector<int> selected(11);
void back(int score, int n, vector<int> info){ // n은 남은 화살의 개수
    if(score == 0){
        int a = 0, l = 0;   // 어피치, 라이언 점수
        selected[10] = n;

        for(int i = 0; i <= 10; i++){   // i는 과녁의 점수, info[i]는 어피치가 맞춘 과녁의 개수
            if(info[i] == selected[i] || info[i] > selected[i]){    // 어피치가 더 많이 맞췄거나, 동일하게 맞춘 경우
                if(info[i] != 0) a += (10 -i);
            }else{  // 라이언이 더 많이 맞춘 경우
                l += (10-i);
            }
        }

        if(a < l){   // 라이언 점수가 더 높은 경우
            win = true;
            if(l - a == diff){  // 같은 점수차로 이긴 경우
                for(int i = 10; i >= 0; i--){   // 낮은 점수를 더 많이
                    if(result[i] < selected[i]){
                        for(int j = 10; j >= 0; j--){
                            result[j] = selected[j];
                        }
                        break;
                    }else if(result[i] > selected[i]){
                        break;
                    }
                }
            }else if(l - a > diff){  // 더 큰 점수차로 이긴 경우
                diff = l - a;
                for(int j = 10; j >= 0; j--){    // 점수 결과를 변경
                    result[j] = selected[j];
                }
            }
        }
    }else{
        // 안 맞추거나
        // 하나 더 많이 맞추거나

        selected[10 - score] = 0;
        back(score - 1, n, info);

        if(info[10 - score] + 1 <= n){
            selected[10 - score] = info[10 - score] + 1;
            back(score - 1, n - (info[10 - score] + 1), info);
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    back(10, n, info);

    if(!win){   // 진 경우
        answer.push_back(-1);
        return answer;
    }else{  // 이긴 경우
        return result;
    }
}