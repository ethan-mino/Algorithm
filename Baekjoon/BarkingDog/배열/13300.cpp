#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    double arr[6][2] = {};

    for(int i = 0; i < n; i++){
        int gen, grade;
        cin >> gen >> grade;
        arr[grade - 1][gen] ++;
    }

    int cnt = 0;

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 2; j++){

            cnt += ceil(arr[i][j] / k);
        }
    }
    cout << cnt;
}
