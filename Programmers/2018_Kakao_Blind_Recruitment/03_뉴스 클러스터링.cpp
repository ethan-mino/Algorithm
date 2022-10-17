// Created by 길민호 on 2022/10/17.

#include <bits/stdc++.h>

using namespace std;

#define KEY first
#define CNT second

vector<string> getKeys(map<string, int> m){
    vector<string> keys;
    std::transform(m.begin(), m.end(), std::back_inserter(keys),
                   [](const auto &pair){
                       return pair.first;
                   });

    sort(keys.begin(), keys.end());
    return keys;
}

// 두 다중집합 간의 자카드 유사도를 반환하는 함수
vector<string> intersectionSet(map<string, int>& set1, map<string, int>& set2){
    vector<string> v;
    for(auto elem : set1){
        int minCnt = min(set1[elem.KEY], set2[elem.KEY]);
        for(int i = 0; i < minCnt; i++){
            v.push_back(elem.KEY);
        }
    }
    return v;
}

vector<string> unionSet(map<string, int>& set1, map<string, int>& set2){
    vector<string> keys1 = getKeys(set1);
    vector<string> keys2 = getKeys(set2);
    vector<string> unionedKey;
    set_union(keys1.begin(), keys1.end(), keys2.begin(), keys2.end(), back_inserter(unionedKey));

    vector<string> v;
    for(auto key : unionedKey){
        int maxCnt = max(set1[key], set2[key]);
        for(int i = 0; i < maxCnt; i++){
            v.push_back(key);
        }
    }

    return v;
}

double jacquard(map<string, int>& set1, map<string, int>& set2){
    vector<string> interVector = intersectionSet(set1, set2);
    vector<string> unionVector = unionSet(set1, set2);

    cout << interVector.size() << " " << unionVector.size() << "\n";

    if(interVector.size() == 0 && unionVector.size() == 0) return 1;
    else return (double) interVector.size() / unionVector.size();
}

void upper(string& str){
    for(int i = 0; i < str.size(); i++) str[i] = toupper(str[i]);
}

// 문자열을 두 글자씩 끊어주는 함수
map<string, int> split(string str){
    map<string, int> v;
    upper(str);

    for(int i = 0; i < str.size() - 1; i++){
        string sub = str.substr(i, 2);

        regex re = regex("[A-Z]*");
        if(regex_match(sub, re)){
            v[sub]++;
        }
    }

    return v;
}

int solution(string str1, string str2) {
    map<string, int> set1 = split(str1);
    map<string, int> set2 = split(str2);

//     cout << set1.size() << "\n";
//     for(auto elem : set1) cout << "(" << elem.KEY << " " << elem.CNT << ") ";
//     cout << "\n";

//     cout << set2.size() << "\n";
//     for(auto elem : set2) cout << "(" << elem.KEY << " " << elem.CNT << ") ";
//     cout << "\n";

    double jacquardScore = jacquard(set1, set2);
    int answer = (int) (jacquardScore * 65536);

    return answer;
}
