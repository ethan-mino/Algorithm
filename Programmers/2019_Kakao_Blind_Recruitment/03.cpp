// Created by 길민호 on 2022/10/13.

#include <bits/stdc++.h>

using namespace std;

// powerset을 이용하여 모든 부분집합을 계산하고, 해당 부분집합이

bool selected[10];
int ans = 0;    // 후보키의 개수

bool isUnique(vector<vector<string>>& rows){
    int columnCnt = rows[0].size();  // 컬럼의 개수
    set<vector<string>> candidateKeys;

    // 유일성을 만족하는 지 확인
    for(auto row : rows){
        vector<string> candidateKey;
        for(int i = 0; i < columnCnt; i++){ // 선택된 컬럼만 후보키로 넣어줌
            if(selected[i])
                candidateKey.push_back(row[i]);
        }
        candidateKeys.insert(candidateKey);
    }

    if(candidateKeys.size() == rows.size())    // 유일성을 만족하는 경우
        return true;
    else return false;
}

// 후보키에 추가할 th번째 속성을 선택
void powerSet(int th, int cnt, vector<vector<string>>& rows){
    int columnCnt = rows[0].size();  // 컬럼의 개수

    if(th == columnCnt){
        bool unique = true;
        bool minimal = true;

        if(!isUnique(rows)) unique = false; // 유일성을 만족하지 않는다면 false

        for(int i = 0; i < columnCnt; i++){
            if(selected[i]){
                selected[i] = false;    // 선택된 속성 중 하나를 지움
                if(isUnique(rows)) minimal = false; // 지웠는데도 유일성을 만족한다면 최소성을 만족하지 않는 것
                selected[i] = true;
            }
        }

        if(unique && minimal) ans++;    // 유일성과 최소성을 모두 만족하는 경우 후보키 개수 증가
    }if(th < columnCnt){   // th는 0 ~ columnCnt - 1까지 가능
        selected[th] = true;
        powerSet(th + 1, cnt + 1, rows);   // th번째 선택
        selected[th] = false;

        powerSet(th + 1, cnt, rows);   // th번째 선택하지 않음
    }

}

int solution(vector<vector<string>> rows) {
    powerSet(0, 0, rows);
    return ans;
}
