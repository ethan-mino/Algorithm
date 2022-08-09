#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n, m;
int board[50][50];

int dist(vector<pair<int, int>> & pos){  // 선택된 치킨집에 대한 도시의 치킨 거리를 계산하는 함수
    int dist = 0;   // 도시의 치킨 거리

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 1){   // 각 집의 치킨 거리 계산
                int m = INT_MAX;
                for(auto c : pos)
                    m = min(m, abs(c.x - i) + abs(c.y - j));    
                dist += m;  // 도시의 치킨 거리에 더해줌
            }

    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    vector<pair<int, int>> pos;    // 치킨집의 좌표
    int cnt = 0;    // 치킨집의 개수

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                cnt++; pos.push_back({i, j});
            }
        }
    
    vector<int> np;
    // next_permutation()을 이용하여 combination을 구하기 위한 벡터
    for(int i = 0; i < cnt - m; i++) np.push_back(0);
    for(int i = 0; i < m; i++) np.push_back(1);

    int ans = INT_MAX;
    do{
        vector<pair<int, int>> cur;
        for(int i = 0; i < np.size(); i++){
            if(np[i] == 1)  // 1인 경우
                cur.push_back(pos[i]);  // 선택된 치킨집이므로, 치킨집의 좌표와 매핑
        }
        
        ans = min(ans, dist(cur)); 
    }while(next_permutation(np.begin(), np.end())); // 각각의 경우의 수에 대해 치킨 거리를 계산

    cout << ans;
}