// Created by 길민호 on 2022/10/17.
#include <bits/stdc++.h>

using namespace std;

// 09:00부터 총 n회 t분 간격으로 역에 도착
// 하나의 셔틀에는 최대 m명의 승객이 탈 수 있다.
// 셔틀은 도착했을 때 도착한 순간에 대기열에 선 크루까지 포함해서 대기 순서대로 태우고 바로 출발
// 콘이 셔틀을 타고 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각을 구하여라.
// 같은 시각에 도착한 크루 중 대기열에서 제일 뒤에 선다.
// 모든 크루는 잠을 자야 하므로 23:59에 집에 돌아간다. 따라서 어떤 크루도 다음날 셔틀을 타는 일은 없다.

vector<string> split(string str, char del){
    vector<string> v;
    istringstream ss(str);
    string buff;
    while(getline(ss, buff, del))
        v.push_back(buff);
    return v;
}

int timeToMinute(int hour, int minute){
    return hour * 60 + minute;
}

string minuteToTIme(int minutes){
    int hour = minutes / 60;
    string hourStr = (hour < 10) ? "0" + to_string(hour) : to_string(hour);
    int minute = minutes % 60;
    string minuteStr = (minute < 10) ? "0" + to_string(minute) : to_string(minute);

    return  hourStr + ":" + minuteStr;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int curTime = timeToMinute(9, 0);
    int lastShuttleTime = curTime + (n - 1) * t;    // 마지막 셔틀이 도착하는 시간

    deque<int> arrivalTime; // 크루원들의 도착 시간을 저장한 벡터

    for(auto timeInfo : timetable){
        vector<string> splited = split(timeInfo, ':');
        int hour = stoi(splited[0]);
        int minute = stoi(splited[1]);
        int minuteTime = timeToMinute(hour, minute);  // 크루원의 분 단위 도착 시간

        if(lastShuttleTime >= minuteTime) // 마지막 셔틀 도착 시간 이전에 도착한 크루들을 저장
            arrivalTime.push_back(minuteTime);
    }

    vector<int> shuttleTime = {curTime}; // 셔틀이 도착하는 시각의 배열

    for(int i = 0; i < n - 1; i++){
        curTime += t;
        shuttleTime.push_back(curTime);
    }

    sort(arrivalTime.begin(), arrivalTime.end());   // 크루원들을 도착시간 별로 정렬

    // 첫번째부터, 마지막 셔틀 - 1번째 셔틀에 크루원들을 태움
    for(int i = 0; i < n - 1; i++){
        int curShuttleTime = shuttleTime[i];    // 현재 셔틀의 도착시간
        int curHeadCnt = arrivalTime.size();    // 기다리고 있는 크루원들의 수

        for(int head = 0; head < min(curHeadCnt, m); head++){   // 최대 m명의 크루원들을 태움
            int curCrewArrivalTime = arrivalTime.front(); // 가장 먼저 도착하는 크루원의 도착 시간
            if(curShuttleTime >= curCrewArrivalTime){   // 셔틀 도착 시간 이전에 도착한 크루들을 태움
                arrivalTime.pop_front();
            }else{
                break;
            }
        }
    }

    int conLastTime = 0;    // 콘이 셔틀을 타고 사무실로 갈 수 있는 도착 시각 중 제일 늦은 시각

    cout << arrivalTime.size() << "\n";

    // 콘이 도착 시각 중 제일 늦은 시각을 구하려면, 가장 마지막 셔틀에 탑승하면 됨
    if(arrivalTime.size() > 0){ // 마지막 셔틀 버스에 탈 수 있는 크루원들이 존재하는 경우
        if(arrivalTime.size() < m){ // 모든 크루원들을 태우고도 자리가 남는 경우,
            conLastTime = lastShuttleTime; // 마지막 셔틀이 도착하는 시간이 가장 늦은 시간
        }else{  // 모든 크루원들을 태울 경우, 셔틀에 자리가 남지 않는 경우,
            conLastTime = arrivalTime[0] - 1; // 최소한 가장 앞에 있는 크루원보다 1분 일찍 와야 함
            int onBoardCnt = 0;
            for(int curCrewIdx = 0; curCrewIdx < arrivalTime.size() - 1; curCrewIdx++){
                onBoardCnt++;
                if(arrivalTime[curCrewIdx] != arrivalTime[curCrewIdx + 1]){ // 같은 시각에 도착한 크루 중 대기열의 가장 뒤라면,
                    if(onBoardCnt < m){
                        conLastTime = arrivalTime[curCrewIdx + 1] - 1;
                    }
                }
            }
        }
    }else{
        conLastTime = lastShuttleTime; // 마지막 셔틀이 도착하는 시간이 가장 늦은 시간
    }

    return minuteToTIme(conLastTime);
}
