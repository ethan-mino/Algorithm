// Created by 길민호 on 2022/10/17.

#include <bits/stdc++.h>

using namespace std;

map<string, int> dict;

vector<int> solution(string msg) {
    int lastIdx = 1; // 사전의 마지막 색인 번호
    vector<int> index;
    for(char cur = 'A'; cur <= 'Z'; cur++) dict[string(1, cur)] = lastIdx++;

    for(int st = 0; st < msg.size(); st++){
        for(int len = msg.size() - st; len >= 1 ; len--){
            string w = msg.substr(st, len);

            if(dict.find(w) != dict.end()){   // 가장 긴 문자열 w를 찾는다.
                index.push_back(dict[w]);   // w에 해당하는 사전의 색인 번호를 출력
                if(st + len < msg.size()){ // 다음문자가 남아있다면,
                    string wc = w + msg[st + len];
                    dict[wc] = lastIdx++;   // wc에 해당하는 단어를 사전에 등록한다.
                }
                st = st + len - 1;
                break;
            }
        }
    }

    return index;
}