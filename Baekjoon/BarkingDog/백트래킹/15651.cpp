#include <bits/stdc++.h>
using namespace std;

int selected[8];
int n, m;

void back(int th){   // m - th개의 숫자를 선택하는 함수 (같은 수 여러번 가능)
    if(th == m){
        for(int i = 0; i < m; i++) cout << selected[i] << " ";
        cout << "\n";
    }else{
        for(int i = 0; i < n; i++){
            selected[th] = i + 1;
            back(th + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    back(0);
}