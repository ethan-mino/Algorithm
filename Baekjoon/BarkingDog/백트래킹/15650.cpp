#include <bits/stdc++.h>
using namespace std;

bool isused[8];
int selected[8];
int n, m;

void back(int r, int th){   // r ~ n - 1 범위에서 m - th개의 숫자를 선택하는 함수
    if(th == m){
        for(int i = 0; i < m; i++) cout << selected[i] << " ";
        cout << "\n";
    }else{
        for(int i = r; i < n; i++){
            if(!isused[i]){
                isused[i] = true; selected[th] = i + 1;
                back(i + 1, th + 1);
                isused[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    back(0, 0);
}