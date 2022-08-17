#include <bits/stdc++.h>
using namespace std;

int d[501][501];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> tri(501, vector<int>(1));

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            int c; cin >> c;
            tri[i].push_back(c);
        }
    }

    d[1][1] = tri[1][1];
    for(int i = 2; i <= n; i++){    // i는 층을 나타냄 (1 ~ 500)
        // i번째 층에는 i개의 칸이 있음
        for(int j = 1; j <= i; j++){ // j는 칸을 나타냄 (1 ~ 500)
            int left = j - 1, right = j;
            d[i][j] += tri[i][j];
            if(left > 0 && right <= i - 1){ // 왼쪽 오른쪽 모두 있는 경우
                d[i][j] += max(d[i - 1][left], d[i - 1][right]);
            }else if(right <= i - 1){   // 오른쪽만 있는 경우
                d[i][j] += d[i - 1][right];
            }else{  // 왼쪽만 있는 경우
                d[i][j] += d[i - 1][left];
            }
        }
    }

    cout << *max_element(d[n], d[n] + n + 1);
}   

