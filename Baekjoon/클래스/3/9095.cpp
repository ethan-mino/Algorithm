#include <bits/stdc++.h>
using namespace std;

int selected[11];

int n, m, ans = 0;
void back(int th){
    int s = 0;
    for(int i = 0; i < th - 1; i++) s += selected[i];   // 현재까지 선택한 수를 합함
    
    if(s == m){ // 선택된 수가 m인 경우 방법 + 1
        ans++;
    }else if(s < m){    // 더 선택할 수 있는 경우
        for(int i = 1; i <= 3; i++){    // 1, 2, 3 중에 선택
            selected[th - 1] = i;
            back(th + 1);   // th + 1번째 수 선택
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> m;
        ans = 0;
        back(1);    // th번째부터 선택하여 m을 만드는 백트래킹을 수행
        cout << ans << "\n";
    }
}