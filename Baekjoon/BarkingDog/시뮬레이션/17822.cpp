#include <bits/stdc++.h>
using namespace std;

#define NOT_EXIST 0
int dx[4] = {-1, 0, 1, 0}; // 상하좌우
int dy[4] = {0, 1, 0, -1};

int n, m, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;

    vector<deque<int>> q(n + 1), temp(n + 1);   // 시계 방향과 반시계 방향으로 회전시킬 수 있으므로 deque를 사용
    for(int i =1 ; i <= n; i++)
        for(int j = 0; j < m; j++){
            int c; cin >> c;
            q[i].push_back(c);
        }

    for(int i = 0; i < t; i++){ // T번 회전
        int x, d, k; cin >> x >> d >> k;
        for(int c = x; c <= n; c +=x){   // x의 배수인 원판을 회전
            for(int r = 0; r < k; r++){ // t번 회전
                if(d == 1){ // 반시계 방향
                    q[c].push_back(q[c].front());
                    q[c].pop_front();
                }else{
                    q[c].push_front(q[c].back());
                    q[c].pop_back();
                }
            }
        }
        copy(q.begin(), q.end(), temp.begin());

        bool equal = false;
        for(int c = 1; c <= n; c++){
            // 인접한 칸을 확인 (일괄 확인해야함)
            for(int j = 0; j < m; j++){ // 원판의 각 원소에 대해 반복

                if(q[c][j] != NOT_EXIST){
                    for(int dir = 0; dir < 4; dir++){
                        int nx = c + dx[dir];
                        int ny = j;

                        if(dy[dir] == 1) ny = (ny + dy[dir]) % m;
                        else ny = (ny + dy[dir] < 0) ? m - 1 : ny + dy[dir];    // 원형이므로 MOD 연산

                        if(nx < 1 || nx >= n + 1) continue;
                        if(q[nx][ny] <= NOT_EXIST) continue;

                        if(q[nx][ny] == q[c][j]){
                            temp[c][j] = NOT_EXIST;
                            temp[nx][ny] = NOT_EXIST;
                            equal = true;
                        }
                    }
                }
            }
        }

        int sum = 0;
        double avg = 0; // 원판의 평균
        int cnt = 0;    // 원판에 남아있는 수의 개수
        for(int c = 1; c <= n; c++){
            for(int j = 0; j < m; j++) {
                if(q[c][j] != NOT_EXIST) cnt++;
                sum += q[c][j];
            }
            avg = (double) sum / cnt;
        }

        if(!equal && cnt > 0){ // 인접하면서, 같은 수가 없는 경우
            for(int c = 1; c <= n; c++){
                for(int j = 0; j < m; j++){
                    if(q[c][j] > NOT_EXIST){
                        if(q[c][j] > avg) temp[c][j]--;
                        if(q[c][j] < avg) temp[c][j]++;
                    }
                }
            }
        }
        copy(temp.begin(), temp.end(), q.begin());
    }

    int sum = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < m; j++)
            sum += q[i][j];
    cout << sum << "\n";
}