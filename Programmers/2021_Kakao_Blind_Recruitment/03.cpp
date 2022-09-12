// Created by 길민호 on 2022/09/12.
#include <bits/stdc++.h>

using namespace std;

#define score first
#define infoId second
typedef pair<int, int> pii;

// s[th][v]는 th번째 카테고리의 v번째 value를 가진 info들의 벡터
// a의 각 카테고리는 개발언어, 직군, 경력, 소울푸드
vector<pii> s[4][3];
// cnt[th]는 th번째 카테고리에 속한 value의 개수
int cnt[4] = {3, 2, 2, 2};
// string은 각 카테고리의 어떤 value가 union되었는지 나타내는 문자열, vector<pii>는 각 카테고리의 value를 가진 info 벡터들의 합집합
map<string, vector<pii>> unionedMap;

// * 문자열을 구분 문자를 기준으로 split 해주는 함수
vector<string> split(string& str, char delimeter){
    vector<string> v;
    istringstream ss(str);
    string stringBuffer;

    while (getline(ss, stringBuffer, delimeter))
        v.push_back(stringBuffer);
    return v;
}

// * des 벡터를 초기화 한 후, src 벡터를 des 벡터에 복사하는 함수
void copyVector(vector<pii>& src, vector<pii>& des){
    des.clear();
    for(auto v : src) des.push_back(v);
}


// * a, b 벡터를 교집합 한 후, result 벡터에 넣어주는 함수
void intersection(vector<pii>& a, vector<pii>& b, vector<pii>& result){
    vector<pii> buff(a.size() + b.size());

    auto iter = set_intersection(a.begin(), a.end(), b.begin(), b.end(), buff.begin());
    buff.erase(iter, buff.end());

    copyVector(buff, result);
}

// 부분집합을 구하여 각 부분집합의 교집합을 구하는 함수
// th는 카테고리의 index를 나타냄
// preIntersect는 현재까지 교집합된 벡터를 나타냄
void powerSet(int th, string& combination, vector<pii>& preIntersect){
    if(th == 4){ // 부분집합이 구해진 경우
        unionedMap[combination] = preIntersect;  // map에 {combination : preIntersect}를 기록
    }else{
        vector<pii> totalUnion;    // th번째 카테고리의 모든 value에 속하는 info 벡터의 합집합을 저장하는 벡터
        string tempCombination;    // 임시 combination

        sort(preIntersect.begin(), preIntersect.end());    // 교집합 하기 위해 sort 수행

        for(int sel = 0; sel < cnt[th]; sel++){    // th번째 카테고리의 각 value를 선택 해봄
            vector<pii> tmpIntersect;  // preIntersect와 th번째 카테고리의 sel번째 value에 속하는 info 벡터의 교집합을 저장할 벡터

            tempCombination = combination + to_string(sel);
            intersection(preIntersect, s[th][sel], tmpIntersect); // 이전 교집합 벡터와 현재 선택한 벡터를 교집합

            powerSet(th + 1, tempCombination, tmpIntersect);   // 백트래킹

            copy(s[th][sel].begin(), s[th][sel].end(), back_inserter(totalUnion)); // 현재 벡터를 합집합
        }

        sort(totalUnion.begin(), totalUnion.end());    // 교집합 전, 합집합된 벡터를 정렬

        vector<pii> tmpIntersect;  // 교집합된 벡터를 저장할 벡터
        intersection(preIntersect, totalUnion, tmpIntersect);  // 합집합된 벡터와 이전 교집합 벡터와 교집합

        // .은 해당 카테고리의 모든 value에 속한 info 벡터를 합집합 했음을 나타냄
        tempCombination = combination + ".";

        powerSet(th + 1, tempCombination, tmpIntersect);   // 백트래킹
    }
}

vector<int> solution(vector<string> infos, vector<string> queries) {
    vector<int> answer;

    map<string, int> m = {{"cpp", 0}, {"java", 1}, {"python", 2},
                          {"backend", 0}, {"frontend", 1},
                          {"junior", 0}, {"senior", 1},
                          {"chicken", 0}, {"pizza", 1}};

    for(int infoIdx = 0; infoIdx < infos.size(); infoIdx++){
        auto info = infos[infoIdx];

        vector<string> splited = split(info, ' ');  // 공백을 기준으로 split
        int score = stoi(splited[splited.size() - 1]);  // 해당 info의 점수

        for(int th = 0; th < splited.size() - 1; th++){ // info의 value를 각 카테고리에 넣어줌
            s[th][m[splited[th]]].push_back({score, infoIdx});
        }
    }


    // 교집합을 수행해야하므로, 정렬 수행
    for(int th = 0; th < 4; th++)
        for(int j = 0; j < cnt[th]; j++)
            sort(s[th][j].begin(), s[th][j].end());

    // 첫번째 카테고리의 각 value를 선택한 뒤, 백트래킹 수행
    // preIntersect에 빈 벡터를 넣어주어서 백트래킹을 수행하면, 교집합을 결과가 빈 벡터가 되기 때문에 이러한 방식을 사용
    vector<pii> total;
    for(int f = 0; f < 3; f++){
        string com = to_string(f);
        powerSet(1, com, s[0][f]);
        copy(s[0][f].begin(), s[0][f].end(), back_inserter(total));
    }

    // 첫번째 카테고리를 모두 합집합한 후, 백트래킹 진행
    string tempCom = ".";
    powerSet(1, tempCom, total);

    for(auto query : queries){
        string replaced = regex_replace(query, regex("and "), "");  // "and "를 공백으로 치환
        vector<string> splited = split(replaced, ' ');  // 공백을 기준으로 query를 split
        int score = stoi(splited[splited.size() - 1]);  // query의 점수

        string combination = "";    // query가 필요로 하는 combination
        for(int th = 0; th < 4; th++){
            string cur = (splited[th] != "-") ? to_string(m[splited[th]]) : ".";    // -는 해당 조건을 고려하지 않으므로 '.'으로 치환
            combination += cur;
        }

        vector<pii>& target = unionedMap[combination];  // query가 필요로 하는 조건에 속한 info들의 벡터

        auto idx = lower_bound(target.begin(), target.end(), pii(score, -1)) - target.begin();  // 해당 info 벡터에서 score 이상의 점수를 가진 info의 idx
        answer.push_back(target.size() - idx);  // query를 만족하는 info의 수 push
    }

    return answer;
}
