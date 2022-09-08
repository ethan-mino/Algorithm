// Created by 길민호 on 2022/09/08.
#include <bits/stdc++.h>

using namespace std;
map<string, int> cnt;
bool cSize[11];

// menus의 부분집합을 모두 찾아보고, map에 {코스를 나타내는 문자열, 해당 코스를 주문한 손님의 수}를 저장
void powerSet(int th, string& menus, string course){
    if(th == menus.size()){
        cnt[course]++;
    }else{
        powerSet(th + 1, menus, course + menus[th]);
        powerSet(th + 1, menus, course);
    }
}

vector<string> solution(vector<string> orders, vector<int> courseSizes) {
    // 각 손님별로 모든 부분집합을 계산, map에 횟수를 count
    for(auto order : orders) {
        sort(order.begin(), order.end());   // 손님이 주문한 메뉴를 나타내는 문자열을 사전순으로 정렬
        powerSet(0, order, ""); // 주문한 메뉴의 가능한 모든 부분집합을 찾은 뒤, map에 각 부분집합이 등장하는 수를 count
    }

    for(auto courseSize : courseSizes) cSize[courseSize] = true;    // 추가하고 싶은 코스 요리의 크기를 map에 저장하여, O(1)에 확인

    // {해당 코스를 주문한 손님의 수, 해당 코스를 나타내는 문자열}을 저장하는 set(등장 횟수를 기준으로 정렬)
    set<pair<int, string>> sortedByOrdered;
    for(auto info : cnt){
        sortedByOrdered.insert({info.second, info.first});
    } 

    int maxCourse[11];  // 코스 메뉴의 사이즈별 최대 주문 횟수
    vector<string> answer;
    // 코스 메뉴의 사이즈별 최대 주문 횟수를 2로 초기화하여, 최소 2명 이상의 손님으로부터 주문된 단품 메뉴 조합에 대하서면 후보로 포함
    fill(maxCourse, maxCourse + 11 , 2);

    auto iter = prev(sortedByOrdered.end());    // 가장 많이 주문된 코스부터 확인

    do{
        int courseCnt = iter->first;   // 해당 코스를 주문한 손님의 수
        string course = iter->second;   // 해당 코스를 나타내는 문자열

        // 추가하려는 코스 요리의 크기이며, 해당 코스 크기 중 손님이 가장 많이 주문한 메뉴인 경우 answer에 추가
        if(cSize[course.size()] && maxCourse[course.size()] <= courseCnt){
            maxCourse[course.size()] = courseCnt;
            answer.push_back(course);
        }
        iter--; // 다음으로 가장 많이 주문한 메뉴를 확인
    }while(iter != sortedByOrdered.begin());

    sort(answer.begin(), answer.end()); // 오름차순으로 정렬하여 반환
    return answer;
}