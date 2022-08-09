#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

#define sec first
#define dir second

int n, k, l;
tuple<bool, int, int> apple[100];
queue<pair<int, char>> head; 
deque<pair<int, int>> sneak;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        apple[i] = {true, x, y};
    }
        
    
    cin >> l;
    for(int i =0; i < l; i++){
        pair<int, char> inf;
        cin >> inf.sec >> inf.dir;
        head.push(inf);
    }

    int time = 0;
    tuple<int, int, int> cur = {1, 1, 1}; 
    sneak.push_back({1, 1});

    while(true){
        time++; // 시간 증가

        int nx = get<0>(cur) + dx[get<2>(cur)];
        int ny = get<1>(cur) + dy[get<2>(cur)];
        
        bool touch = false; // 뱀과 부딫혔는지를 나타내는 flag
        for(int i = 0; i < sneak.size(); i++)
            if(sneak[i].x == nx && sneak[i].y == ny) touch = true;  

        if(nx < 1 || ny < 1 || nx > n || ny > n || touch) break;    // 벽 또는 자기 자신과 부딪힌 경우

        get<0>(cur) = nx; get<1>(cur) = ny; // 방향에 따라 한 칸 이동
        sneak.push_back({nx, ny});  // 몸 길이를 늘려준다

        bool a = false; // 이동하는 칸에 사과가 있는지를 나타내는 flag
        for(int i = 0; i < k; i++)
            if(get<0>(apple[i]) && get<1>(apple[i]) == nx && get<2>(apple[i]) == ny){
                get<0>(apple[i]) = false;   // 칸에 있던 사과는 없어진다
                a = true; break;
            }
                
        if(!a) {sneak.pop_front();} // 이동하는 칸에 사과가 없다면, 꼬리가 위치한 칸을 비워준다

        if(!head.empty() && head.front().sec == time){   // 방향을 틀어야하는 경우
            if(head.front().dir == 'D') get<2>(cur) = (get<2>(cur) + 1) % 4;    // 오른쪽인 경우
            else get<2>(cur) = (get<2>(cur) == 0) ? 3 : get<2>(cur) - 1; // 왼쪽인 경우
            head.pop(); // 방향 정보는 초가 증가하는 순이므로, pop()
        }
    }

    cout << time;
}
