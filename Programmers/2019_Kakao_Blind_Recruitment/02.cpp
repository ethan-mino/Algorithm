// Created by 길민호 on 2022/10/13.

#include <bits/stdc++.h>

using namespace std;

string splited[1000010][3];

vector<string> split(string str, char delim){
    vector<string> v;
    istringstream ss(str);
    string buff;

    while(getline(ss, buff, delim))
        v.push_back(buff);
    return v;
}

vector<string> solution(vector<string> records) {
    vector<string> answer;
    map<string, string> nicknameMap; // uid, nickname를 저장하는 map

    for(int i = 0; i < records.size(); i++){
        vector<string> splitedStr = split(records[i], ' ');
        for(int j = 0; j < splitedStr.size(); j++)
            splited[i][j] = splitedStr[j];

        string op = splited[i][0];
        string uid = splited[i][1];

        if(op == "Change" || op == "Enter"){ // 닉네임을 변경한 경우
            string nickname = splited[i][2];
            nicknameMap[uid] = nickname;    // 닉네임 업데이트
        }
    }


    for(int i = 0; i < records.size(); i++){
        string op = splited[i][0];
        string uid = splited[i][1];

        if(op == "Enter"){
            answer.push_back(nicknameMap[uid] + "님이 들어왔습니다.");
        }else if(op == "Leave"){
            answer.push_back(nicknameMap[uid] + "님이 나갔습니다.");
        }
    }

    return answer;
}
