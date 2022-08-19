#include <bits/stdc++.h>
using namespace std;

#define period first 
#define cost second 

pair<int, int> arr[1500010];
int n, d[1500010]; // i번째 일까지 상담했을 때 얻는 최대 이익

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);     

    cin >> n;
    // 각 상담을 완료하는데 걸리는 기간과 받을 수 있는 금액을 입력 받음
    for(int i = 1; i <= n; i++) cin >> arr[i].period >> arr[i].cost;    

    // Bottom-Up Dynamic programming
    for(int i = 1; i <= n; i++){    
        // d는 i번째 일까지 상담했을 때 얻는 최대 이익이므로, 기존의 최대 이익이 이어짐 
        if(d[i] == 0) d[i] = d[i - 1];  
        else d[i] = max(d[i], d[i - 1]);

        if(d[i + arr[i].period] == 0)   // i번째 상담이 종료되는 날에 수익을 기록
            d[i + arr[i].period] = d[i] + arr[i].cost;  // i번째 일까지 상담했을 때 얻는 최대 이익 + i번째 상담의 비용
        else    // 이미 수익이 기록되어 있는 경우 
            d[i + arr[i].period] = max(d[i] + arr[i].cost, d[i + arr[i].period]); // 더 많은 수익을 기록
    }

    cout << *max_element(d + 1, d + n + 2);
}

/* 2번째 풀이
#include <bits/stdc++.h>
using namespace std;

#define SIZE 1510000
int term[SIZE];
int price[SIZE];
int d[SIZE];    // d[i]는 i - 1일까지 상담했을 때, 백준이가 얻을 수 있는 최대 수익

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> term[i] >> price[i];
    }

    d[1] = 0;
    for(int i = 1; i <= n + 1; i++){
        int nx = i + term[i];
        d[i] = max(d[i], d[i - 1]);
        d[nx] = max(d[nx], d[i] + price[i]);
    }

    cout << d[n + 1] << "\n";
}
*/

/*
1   2   3   4   5   6   7   8   9   10  
5   4   3   2   1   1   2   3   4   5
50  40  30  20  10  10  20  30  40  50

1   2   3   4   5   6   7   8   9   10  
0   0   0   0   0   50  60      80
*/