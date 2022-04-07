#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> accu = {0}; // 누적 배열
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int t; cin >> t; 
        sum += t;
        accu.push_back(sum);    // 입력 받으면서 누적 배열을 만듦.
    }

    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        cout << accu[y] - accu[x - 1] << "\n";  // 구간 합 출력
    }
}   
