// Created by SSAFY on 2022-09-21.
#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = INT_MAX;

    for(int unit = 1; unit <= s.size(); unit++){
        int start = 0;
        vector<string> split;
        while(start < s.size()){
            string sub;
            if(start + unit >= s.size()) sub = s.substr(start, s.size() - start);
            else sub = s.substr(start, unit);

            start += unit;
            split.push_back(sub);
        }

        int len = 0;
        int cur = 0;
        string com = "";
        while(cur < split.size()){
            int nx = cur + 1;
            while(nx < split.size() && split[cur] == split[nx]) nx++;
            int dup = nx - cur;
            if(dup > 1){
                com.append(to_string(dup) + split[cur]);
            }else{
                com.append(split[cur]);
            }
            cur = nx;
        }
        answer = min(answer, (int) com.size());
    }
    return answer;
}