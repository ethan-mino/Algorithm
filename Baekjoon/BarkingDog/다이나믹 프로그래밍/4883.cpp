#include <bits/stdc++.h>
using namespace std;

int graph[100010][3], d[100010][3]; // d[i][j]는 i행 j열로 이동하는 최소 비용
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    while(true){
        int n; cin >> n;  
        if(!n) break;
        fill(&graph[0][0], &graph[100009][3], 0);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 3; j++)
                cin >> graph[i][j]; // 삼각 그래프 입력 받음

        // 초기값 지정
        d[0][0] = INT_MAX, d[0][1] = graph[0][1], d[0][2] = graph[0][1] + graph[0][2];
        
        // 테이블 채우기
        for(int i = 1; i < n; i++){
            d[i][0] = min({d[i - 1][0], d[i - 1][1]}) + graph[i][0];
            d[i][1] = min({d[i - 1][0], d[i - 1][1], d[i - 1][2], d[i][0]}) + graph[i][1];
            d[i][2] = min({d[i - 1][1], d[i - 1][2], d[i][1]}) + graph[i][2];
        }

        cout << t++ << ". " << d[n - 1][1] << "\n"; // 가장 하단의 가운데 정점까지의 최소 비용
    }
}   