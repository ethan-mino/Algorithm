// Created by 길민호 on 2022/06/09.

#include <bits/stdc++.h>
using namespace std;

int dist[21][21];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> dist[i][j];

    int ans = 0;
    for(int st = 1; st <= n; st++){
        for (int en = 1; en <= n; en++){
            if(st != en){
                bool edge = true;
                for(int pass = 1; pass <= n; pass++){
                    if(st != pass && en != pass){
                        int a = dist[st][en];
                        int b = dist[st][pass] + dist[pass][en];
                        if(a == b) edge = false;
                        else if(a > b) {
                            cout << -1 << "\n";
                            return 0;
                        }
                    }
                }

                if(edge) ans += dist[st][en];
            }
        }
    }
    cout << ans / 2 << "\n";
}
// 도시 A에서 도시 B로 바로 갈 수 있는 도로가 있거나, 다른 도시를 거쳐서 갈 수 있을 때, 도시 A에서 B를 갈 수 있다고 한다.
