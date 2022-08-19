#include <bits/stdc++.h>
using namespace std;

int selected[8];
int n, m;

void back(int r, int th){   // r ~ n - 1 범위에서 m - th개의 숫자를 선택하는 함수 (같은 수 여러 번 골라도 됨)
    if(th == m){
        for(int i = 0; i < m; i++) cout << selected[i] << " ";
        cout << "\n";
    }else{
        for(int i = r; i < n; i++){
            selected[th] = i + 1;
            back(i, th + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    back(0, 0);
}