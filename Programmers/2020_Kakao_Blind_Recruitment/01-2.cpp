// Created by SSAFY on 2022-09-16.

#include <bits/stdc++.h>

#define u first
#define v second

using namespace std;

// str이 올바른 괄호 문자열인지 반환하는 함수
bool isCorrect(string & str){
    stack<char> s;

    for(auto c : str){
        if(c == '('){  // 여는 괄호인 경우
            s.push('(');
        }else{  // 닫는 괄호인 경우
            if(s.empty()){  // 스택이 비어있는 경우
                return false;
            }else{  // 스택에 요소가 존재하는 경우
                s.pop();
            }
        }
    }

    if(!s.empty()) return false;
    return true;
}

// 균형잡힌 괄호 문자열 w를 균형잡힌 괄호 문자열 u, v로 분리해주는 함수
pair<string, string> splitStr(string str){
    int open = 0, close = 0;
    string u = "", v = "";

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(') open++;
        else close++;

        if(open == close) { // u는 균형 잡힌 문자열 중 가장 짧은 문자열
            u = str.substr(0, i + 1);
            v = str.substr(i + 1, str.size() + 1);
            break;
        }
    }
    return {u, v};
}

// 괄호 방향을 뒤집은 문자열을 반환하는 함수
string reverse(string str){
    string result = "";
    for(auto c : str){
        if(c == ')') result += '(';
        else result += ')';
    }
    return result;
}

// 균형잡힌 괄호 문자열을 올바른 괄호 문자열로 변환해주는 함수
string makeCorrect(string str){
    // 빈 문자열인 경우, 빈 문자열을 반환
    if(str == "") return "";

    // 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다.
    // 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
    string u, v;
    tie(u, v) = splitStr(str);

    // 문자열 u가 "올바른 괄호 문자열" 이라면
    if(isCorrect(u)){
        // 문자열 v에 대해 1단계부터 다시 수행
        // 수행한 결과 문자열을 u에 이어 붙인 후 반환
        return u + makeCorrect(v);
    }else{  // 문자열 u가 "올바른 괄호 문자열"이 아니라면
        return "(" // 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
               + makeCorrect(v) // 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
               + ")" // ')'를 다시 붙입니다.
               + reverse(u.substr(1, u.size() - 2));   // u의 첫 번째와 마지막 문자를 제거하고
        // 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
    }
}

string solution(string p) {
    return makeCorrect(p);
}