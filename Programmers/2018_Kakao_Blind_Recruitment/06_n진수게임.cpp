// Created by 길민호 on 2022/10/17.
#include <bits/stdc++.h>

using namespace std;

string baseToStr(int base, int num){
    if(num == 0) return "0";
    map<int, string> m = {{10 , "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}};
    string ans = "";

    int cur = num;
    while(cur > 0){
        int remain = cur % base;
        ans += (remain >= 10) ? m[remain] : to_string(remain);
        cur /= base;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

string solution(int base, int t, int m, int p) {
    // 참가하는 인원 m
    // p, m + p, (2 * m) + p번째 문자
    // 총 개수 m * (t - 1) + p개 필요

    int totalCnt = m * (t - 1) + p;
    string order = " ";
    int cur = 0;
    while((order.size() - 1) < totalCnt){
        order += baseToStr(base, cur);
        cur++;
    }

    string answer = "";
    for(int n = 0; n < t; n++){
        int idx = m * n + p;
        answer += order[idx];
    }

    return answer;
}
