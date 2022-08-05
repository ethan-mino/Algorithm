// Created by 길민호 on 2022/08/05.
// 15:31 ~
#include <bits/stdc++.h>
using namespace std;

int n;
int board[21][21];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // 종아하는 학생인지 아닌지 배열을 순회화며 확인하지 않기 위해 map을 사용
    vector< pair<int, map<int, bool>>> v(n * n);
    map<int, map<int, bool>> m;

    for(int i =0 ; i < n * n; i++){
        int s; cin >> s;
        map<int, bool> f;
        for(int j = 0, c; j < 4; j++) {
            cin >> c;
            f[c] = true;
        }
        v[i] = {s, f};  // v[idx]는 idx번째로 자리를 배정하는 학생 s와 해당 학생 학생이 종아하는 학생 벡터의 pair
        m[s] = f;   // key : 학생의 번호, value : 해당 학생이 좋아하는 학생 번호 벡터
    }

    for(int o = 0; o < n * n ; o++){ // 각 학생을 자리에 배정
        tuple<int, int, int, int> pos = {INT_MIN, INT_MIN, INT_MIN, INT_MIN}; // 좋아하는 학생의 수, 비어있는 칸의 수, 행의 번호, 열의 번호

        for(int i = 0; i < n; i++){ // 각 좌석을 확인
            for(int j = 0; j < n; j++){
                if(board[i][j] == 0){   // 배정되지 않은 자리라면,
                    int cnt = 0;    // 인접한 칸 중 비어있는 칸의 개수
                    int f = 0;  // 인접한 좋아하는 학생의 수
                    for(int dir = 0; dir < 4; dir++){   // 인접한 좌석 확인
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] == 0) {    // 빈칸인 경우
                            cnt++;
                            continue;
                        }

                        if(v[o].second[board[nx][ny]]) f++; // 좋아하는 학생인 경우
                    }

                    // 종아하는 학생과 빈 칸의 개수는 많은 순이지만, 좌표는 작은 순이라 정렬을 사용하지 않음
                    tuple<int, int, int, int> cur = {f, cnt, i, j};
                    if(get<0>(pos) < f) pos = cur;
                    else if(get<0>(pos) == f) {
                        if(get<1>(pos) < cnt) pos = cur;
                        else if(get<1>(pos) == cnt){
                            if(get<2>(pos) > i) pos = cur;
                            else if(get<2>(pos) == i){
                                if(get<3>(pos) > j) pos = cur;
                            }
                        }
                    }
                }
            }
        }
        // 가장 높은 우선 순위의 칸에 학생 배정
        board[get<2>(pos)][get<3>(pos)] = v[o].first;
    }

    int sum = 0;    // 학생들의 만족도 합
    for(int i = 0; i < n; i++) { // 각 좌석을 확인
        int s[5] = {0, 1, 10, 100, 1000};
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                // 좋아하는 학생의 인원수에 따라 점수 합계
                if(m[board[i][j]][board[nx][ny]]) cnt++;
            }
            sum += s[cnt];
        }
    }

    cout << sum << "\n";
}