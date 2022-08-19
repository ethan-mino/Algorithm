#include <bits/stdc++.h>
using namespace std;

#define MAX_SECOND 1010
#define MAX_FALL 32
int pos[MAX_SECOND];
int d[MAX_SECOND][MAX_FALL][3]; // d[t][w][p]는 T초에 w번 움직였을 때, p 위치에서 받을 수 있는 자두의 최대 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, w; cin >> t >> w;

    for(int i = 1; i <= t; i++) cin >> pos[i];

    fill(&d[1][0][0], &d[MAX_SECOND - 1][MAX_FALL - 1][3], -1004);
    if(pos[1] == 1){
        d[1][0][1] = 1;
        d[1][1][2] = 0;
    }else{
        d[1][0][1] = 0;
        d[1][1][2] = 1;
    }

    for(int s = 2; s <= t; s++){
        for(int m = 0; m <= w; m++){
            // 위치를 옮긴 경우
            d[s][m + 1][1] = max(d[s - 1][m + 1][1], d[s - 1][m][2]);
            d[s][m + 1][2] = max(d[s - 1][m + 1][2], d[s - 1][m][1]);

            // 위치를 옮기지 않은 경우
            d[s][m][1] = max(d[s][m][1], d[s - 1][m][1]);
            d[s][m][2] = max(d[s][m][2], d[s - 1][m][2]);

            if(pos[s] == 1){
                d[s][m][1]++;
            }else{
                d[s][m][2]++;
            }
        }
    }

    int m = INT_MIN;
    for(int i = 1; i <= t; i++){
        for(int j = 0; j <= w; j++){
            for(int k = 1; k < 3; k++){
                m = max(m, d[i][j][k]);
            }
        }
    }

    cout << m;
}   

/*
8 1
2
1
1
2
2
2
1
1

1 0
1

5 0
2
2
2
2
2

5 1
1
1
1
1
1

17 4
1
1
1
2
2
1
1
1
2
2
2
2
1
1
1
1
1
*/

// 다른 나무에서 떨어질 때마다 이동하는 것이 당연히 더 많은 자두를 먹을 수 있음
// 하지만, 이동 횟수에 제한이 있으므로, 더 많이 움직인다고 많이 먹는 것은 아니며, 가장 많이 먹을 수 있을 때만 움직여함.
// 홀수번 움직이면 2번 나무, 짝수번 움직이면 1번 나무



// n나무, m나무
// 다른 나무에서 자두가 더 많이 떨어질 때 이동
// 최대 ->  
