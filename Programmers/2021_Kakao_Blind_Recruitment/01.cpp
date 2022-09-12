// Created by 길민호 on 2022/09/12.

#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    // 대문자를 모두 소문자로 치환
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    // 알파벳 소문자, 숫자, 빼기, 밑줄, 마침표를 제외한 모든 문자 제거
    new_id = regex_replace(new_id, regex("[^a-z0-9._-]"), "");

    // 마침표가 2번 이상 연속된 부분을 하나의 마침표로 치환
    new_id = regex_replace(new_id, regex("\\.{2,}"), ".");

    // new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거
    new_id = regex_replace(new_id, regex("^\\."), "");
    new_id = regex_replace(new_id, regex("\\.$"), "");
    // 빈 문자열이라면, new_id에 "a"를 대입
    if(new_id.empty()) new_id = "a";

    // new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거
    new_id = new_id.substr(0, 15);
    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거
    new_id = regex_replace(new_id, regex("\\.$"), "");
    // new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    while(new_id.size() <= 2){
        new_id += new_id[new_id.size() - 1];
    }

    return new_id;
}