#include <bits/stdc++.h>
using namespace std;

const int MAX_CHANNEL = 1000000;
deque<int> avail;  // 숫자 버튼으로 이동 가능한 채널의 번호를 저장하는 벡터
int broken[10];
int selected[6];

int countDigit(int num){    // 숫자의 자리수를 반환하는 함수, ex. 1024 -> 4
    return to_string(num).size();
}

void channel(int th){ // 선택 가능한 버튼 7 - th개를 선택하는 함수 (중복 허용)
    if(th == 7){
        int num = 0;
        for(int i = 0; i < 6; i++) num += selected[i] * pow(10, 5 - i); 
        avail.push_back(num); // 이동하려는 채널 번호로 변환
    }else{
        for(int i = 0; i < 10; i++){
            bool zero = true;   // 앞서 선택한 버튼이 모두 0인 경우 true
            for(int j = 0; j < th - 1; j++) 
                if(selected[j] != 0) zero = false;
                
            // 선택 가능한 숫자이거나, 
            // 0이 고장난 버튼이라도, 앞서 선택한 버튼이 모두 0인 경우 0 선택 가능해야함
            // 단, 마지막 숫자를 선택하는 경우, 0이 고장났다면 0을 선택할 수 없음
            if(broken[i] != 1 || (i == 0 && zero && th < 6)){   
                selected[th - 1] = i;
                channel(th + 1);
            }
        }
    }
}

int dx[2] = {-1, 1};
int vis[MAX_CHANNEL];

void bfs(){
    queue<int> q;

    q.push(100);    // 시작 채널인 100을 push
    vis[100] = 1;
    
    sort(avail.begin(), avail.end());   // 만들어진 숫자를 오름차순으로 정렬
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        if(vis[cur] < 7){   
            // queue에 노드가 방문 순서에 따라 들어갈 수 있도록, 채널을 queue에 넣어줌
            while(!avail.empty() && vis[cur] == countDigit(avail.front())){ 
                if(vis[avail.front()] == 0) {  
                    q.push(avail.front()); 
                    vis[avail.front()] = vis[cur] + 1; 
                }
                avail.pop_front();
            }
        }

        for(int dir = 0; dir < 2; dir++){
            int nx = cur + dx[dir]; 
            if(nx < 0 || nx >= MAX_CHANNEL) continue;
            if(vis[nx] != 0) continue;
            q.push(nx);
            vis[nx] = vis[cur] + 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c, num; cin >> n >> c;
    for(int i = 0; i < c; i++){
        cin >> num; broken[num] = 1;
    }

    channel(1); // 이동 가능한 모든 채널 번호 계산
    bfs();  // 최단 거리 계산
    cout << vis[n] - 1;
}

/*
500000
0
0 1 2 3 4 5 6 7 8 9

500000
0
5

0
9
0 2 3 4 5 6 7 8 9

0
10
0 1 2 3 4 5 6 7 8 9

0
8
2 3 4 5 6 7 8 9

100
1
4
*/