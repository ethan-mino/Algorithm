// Created by SSAFY on 2022-09-16.
#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int h, m, s;
}Time;

int prefixSum[400000];
long long accumulated[400000];

// 구분 문자를 기준으로 문자열을 split하여 벡터로 반환하는 함수
vector<string> split(string& str, char delimeter){
    vector<string> v;
    istringstream ss(str);
    string stringBuffer;

    while (getline(ss, stringBuffer, delimeter))
        v.push_back(stringBuffer);
    return v;
}

// 시간을 나타내는 문자열을 Time 구조체로 변환해주는 함수
Time toTime(string time){
    vector<string> splited = split(time, ':');
    Time t = {stoi(splited[0]), stoi(splited[1]), stoi(splited[2])};

    return t;
}

// Time 구조체를 초(sec)로 변환해주는 함수
int timeToSec(Time t){
    return t.h * 3600 + t.m * 60 + t.s;
}

// 초(sec)를 Time 구조체로 변환해주는 함수
Time secToTime(int sec){
    int h = sec / 3600; sec -= h * 3600;
    int m = sec / 60; sec -= m * 60;
    int s = sec;
    return {h, m, s};
}

// digit을 두 자리 digit으로 변환해주는 함수
string makeTimeFormat(int digit){
    string strDigit = to_string(digit);
    if(digit < 10) strDigit = "0" + strDigit;
    return strDigit;
}

// Time 구조체를 문자열로 변환해주는 함수
string timeToString(Time t){
    return makeTimeFormat(t.h) + ":" + makeTimeFormat(t.m) + ":" + makeTimeFormat(t.s);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    for(auto log : logs){
        vector<string> splited = split(log, '-');
        Time startTime = toTime(splited[0]);
        Time endTime = toTime(splited[1]);

        int startSec = timeToSec(startTime);
        int endSec = timeToSec(endTime);

        prefixSum[startSec] += 1;
        prefixSum[endSec] += -1;
    }

    // 영상의 마지막 초
    int endSec = timeToSec(toTime(play_time));

    // 각 초마다 겹친 구간의 개수
    for(int sec = 1; sec < endSec; sec++)
        prefixSum[sec] += prefixSum[sec - 1];

    // 광고의 재생시간 길이(s)
    int advSec = timeToSec(toTime(adv_time));

    // t = 0을 기준으로 한 window에 포함되는 재생시간 계산
    for(int t = 0; t < advSec; t++)
        accumulated[0] += prefixSum[t];

    long long maxAccumulated = accumulated[0];
    int startSec = 0;

    for(int t = 1; t <= endSec - advSec; t++){
        accumulated[t] = accumulated[t - 1];
        accumulated[t] -= prefixSum[t - 1];
        accumulated[t] += prefixSum[t + advSec - 1];

        if(maxAccumulated < accumulated[t]){
            maxAccumulated = accumulated[t];
            startSec = t;
        }
    }

    Time startTime = secToTime(startSec);
    Time tmp = secToTime(maxAccumulated);
    return timeToString(startTime);
}