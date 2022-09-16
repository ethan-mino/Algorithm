// Created by SSAFY on 2022-09-16.

#include <bits/stdc++.h>

using namespace std;

bool iscorrect(string str){
    stack<char> s;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(') s.push('(');
        else{
            if(s.empty()) return false;
            else s.pop();
        }
    }

    if(s.size() != 0) return false;
    return true;
}

pair<string, string> split(string str){
    string u = "", v = "";
    int o = 0, c = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(') o++;
        else c++;
        if(o == c) {
            u = str.substr(0, i + 1);
            v = str.substr(i + 1, str.size() - (i + 1));
            break;
        }
    }

    return {u, v};
}

string solution(string p) {
    string answer = "";
    if(p == "") return "";

    while(true){
        pair<string, string> uv = split(p);
        string u = uv.first, v = uv.second;
        if(iscorrect(u)){   // u가 올바른 괄호 문자열이라면,
            return u.append(solution(v));
        }else{
            string temp = "(";
            temp.append(solution(v)).append(")");
            string temp2 =u.substr(1, u.size() - 2);
            for(int i = 0; i < temp2.size(); i++){
                if(temp2[i] == '(') temp2[i] = ')';
                else temp2[i] = '(';
            }

            return temp.append(temp2);
        }
    }

    return answer;
}