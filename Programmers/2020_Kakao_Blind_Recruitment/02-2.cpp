// Created by SSAFY on 2022-09-21.
#include <bits/stdc++.h>
using namespace std;

string compress(vector<string> units){
    string compressed = "";
    string before = "";
    int cnt = 0;
    for(auto str : units){
        if(str == before){
            cnt++;
        }else if(str != before){
            if(cnt > 1) compressed += to_string(cnt);
            compressed += before;
            before = str;
            cnt = 1;
        }
    }

    if(cnt > 1) compressed += to_string(cnt);
    compressed += before;

    return compressed;
}

int solution(string s) {
    int answer = INT_MAX;

    // len은 자르는 단위의 길이
    for(int len = 1; len <= s.size(); len++){
        int st = 0;
        vector<string> units;

        while(st < s.size()){
            string substr = s.substr(st, len);
            units.push_back(substr);
            st += len;
        }

        string compressed = compress(units);
        if(compressed.size() < answer) answer = compressed.size();
    }
    return answer;
}
