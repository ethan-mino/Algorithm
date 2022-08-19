#include <bits/stdc++.h>
using namespace std;

#define d first
#define w second

pair<int, int> eggs[8];
bool isused[8];
int n, ans = 0;

void eggToegg(int cur){ // cur은 손에 들 계란의 idx
    if(cur == n){
        int cnt = 0;
        for(int i = 0; i < n; i++)
            if(eggs[i].d <= 0) cnt++;
        ans = max(ans, cnt);
    }else{
        if(eggs[cur].d > 0){    //   손에 들고 있는 계란이 깨지지 않은 경우
            bool flag = true;
            for(int i = 0; i < n; i++){ // 깨지지 않은 다른 계란 중에서 하나를 친다.
                if(eggs[i].d > 0 && i != cur){
                    flag = false;
                    eggs[cur].d -= eggs[i].w;
                    eggs[i].d -= eggs[cur].w;

                    eggToegg(cur + 1);  // 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 든다.
                    eggs[cur].d += eggs[i].w;
                    eggs[i].d += eggs[cur].w;
                }
            }
            if(flag) eggToegg(cur + 1); // 깨지지 않은 다른 계란이 없으면 치지 않고 넘어간다.
        }else{  // 손에 들고 있는 계란이 깨진 경우, 치지 않고 넘어간다.
            eggToegg(cur + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> eggs[i].d >> eggs[i].w;

    eggToegg(0);    // 가장 왼쪽의 계란을 듦.
    cout << ans;
}