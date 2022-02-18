#include <bits/stdc++.h>
using namespace std;


int test(vector<vector<int>> v, int n, int m){
    int cnt = 0;
    
    for(int i = n; i < n + 8; i++){
        for(int j = m; j < m + 8; j++){
            if(j + 1 < m + 8 && v[i][j] == v[i][j + 1]){
                v[i][j+1] = 1 - v[i][j + 1];
                cnt++;
            }
            
            if(i + 1 < n + 8 && v[i][j] == v[i + 1][j]){
                v[i + 1][j] = 1 - v[i + 1][j];
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;

    for(int i = 0; i < n; i++){
        vector<int> v1;

        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            (c == 'W') ? v1.push_back(0) : v1.push_back(1);
        }
        v.push_back(v1);
    }

    int mv = 100;

    for(int i = 0; i < n - 7; i++){
        for(int j = 0; j < m - 7; j++){
            int t1 = test(v, i, j);
            v[i][j] = 1 - v[i][j];

            int t2 = test(v, i, j);
            v[i][j] = 1 - v[i][j];

            mv = min({mv, t1, t2 + 1});
        }

        if(mv == 0)
            break;
    }

    cout << mv;
}
