// Created by 길민호 on 2022/08/08.

#include <bits/stdc++.h>
using namespace std;

#define nxt second

int dice[10];
int scores[34] = {0, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38,
             13, 16, 19,
             28, 27, 26,
             22, 24, 25, 30, 35, 40, 0};

int location[4] = {1, 1, 1, 1};
vector<vector<pair<int, int>>> linked(34);

int ans = INT_MIN;

int move(int start, int remain){
    if(start == 6 || start == 11 || start == 16){
        int nx = linked[start][0].nxt;
        start = nx;
        remain--;
    }

    int cur = start;
    for(int i = 0; i < remain; i++){
        int nx = 0;
        if(cur == 6 || cur == 11 || cur == 16)
            nx = linked[cur][1].nxt;
        else nx = linked[cur][0].nxt;

        cur = nx;
        if(cur == 33) break;
    }

    return cur;
}

void back(int th, int score){
    ans = max(ans, score);
    if(th <= 10){
        for(int i = 0; i < 4; i++){
            if(location[i] != 33){
                // 도착하지 않았고,
                int nx = move(location[i], dice[th - 1]);
                int avail = true;

                if(nx != 33){    // 이동을 마치는 칸이 도착칸이 아닌 경우
                    for(int j = 0; j < 4; j++){ // 이동을 마치는 칸에 다른 말들이 있는 지 확인
                        if(i != j)
                            if(location[j] == nx)
                                avail = false;
                    }
                }

                if(avail){
                    int pre = location[i];
                    location[i] = nx;
                    back(th + 1, score + scores[nx]);
                    location[i] = pre;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10; i++) cin >> dice[i];

    linked[6].push_back({3, 21});
    linked[16].push_back({3, 24});
    linked[11].push_back({3, 27});

    linked[20].push_back({1, 32});
    linked[23].push_back({1, 29});
    linked[26].push_back({1, 29});
    for(int i = 1; i <= 19; i++) linked[i].push_back({1, i + 1});   // 0 -> 2 -> ,,, -> 40
    for(int i = 21; i <= 22; i++) linked[i].push_back({1, i + 1});
    for(int i = 24; i <= 25; i++) linked[i].push_back({1, i + 1});
    for(int i = 27; i <= 32; i++) linked[i].push_back({1, i + 1});
    for(int i = 0; i < 34; i++) sort(linked[i].begin(), linked[i].end(), greater<>());

    back(1, 0);
    cout << ans << "\n";
}
