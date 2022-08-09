#include <bits/stdc++.h>
using namespace std;

#define w first
#define p second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, w, l;
    cin >> n >> w >> l;

    queue<int> truck;       // 다리 위에 올라가지 못한 트럭을 저장하는 queue

    for(int i = 0; i < n; i++){ // 각 트럭의 무게 입력 받음
        int w; cin >> w;
        truck.push(w);  
    }

    deque<pair<int, int>> bridge;   // 다리 위에 있는 트럭을 저장하는 queue

    int time = 0;   // 트럭들이 다리를 건너는 최단 시간
    while(!truck.empty() || !bridge.empty()){  // 모두 다리를 건널 때까지 진행
        for(int i = 0; i < bridge.size(); i++) bridge[i].p -= 1; // 다리 위 트럭 앞으로 1씩 이동

        if(!bridge.empty() && bridge.front().p == 0) // 다리를 건넌 트럭은 bridge 큐에서 pop
            bridge.pop_front();

        int weight = 0;   
        for(auto truck : bridge) weight += truck.w ;    // 다리 위에 있는 전체 트럭의 무게 계산

        if(!truck.empty() && truck.front() + weight <= l 
        && bridge.size() < w){    // 다리 위에 트럭이 올라갈 자리가 있고, 다리의 최대 하중이 남은 경우
            bridge.push_back({truck.front(), w});   // 기다리는 트럭 중 가장 앞에 있는 트럭을 다리 위에 올린다.
            truck.pop();
        }

        time++;
    }

    cout << time;
}