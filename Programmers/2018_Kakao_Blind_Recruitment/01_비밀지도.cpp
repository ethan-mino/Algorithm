// Created by 길민호 on 2022/10/14.

#include <bits/stdc++.h>

using namespace std;

string binaryToStr(int binary, int n) {
    string binaryStr = bitset<16>(binary).to_string();
    return binaryStr.substr(16 - n);
}

vector<vector<int>> encryptedToMap(vector<int> encrypted){
    int n = encrypted.size();
    vector<vector<int>> map(n, vector<int>(n));

    for(int i = 0; i < encrypted.size(); i++){
        int binary = encrypted[i];
        string str = binaryToStr(binary, n);
        for(int j = 0; j < str.size(); j++){
            map[i][j] = str[j] - 48;
        }
    }

    return map;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<vector<int>> map1 = encryptedToMap(arr1);
    vector<vector<int>> map2 = encryptedToMap(arr2);

    for(int i = 0; i < n; i++){
        string mapStr = "";
        for(int j = 0; j < n; j++){
            if(map1[i][j] == 0 && map2[i][j] == 0) mapStr += " ";
            else mapStr += "#";
        }
        answer.push_back(mapStr);
    }

    return answer;
}
