// Created by 길민호 on 2022/07/25.
#include <bits/stdc++.h>

int board[50][50];

using namespace std;
int main(){
    int t, n; cin >> t;

    for(int cur = 1; cur <= t; cur++){
        cin >> n;
        for(int i = 0; i < n; i++){
            string str; cin >> str;
            for(int j = 0; j < str.size(); j++){
                board[i][j] = str[j] - 48;
                if(j != 0) board[i][j] += board[i][j - 1];
            }
        }

        int sum = 0;
        int mid = n / 2;
        for(int i = 0; i <= mid; i++){
            sum += board[i][mid + i] - board[i][mid - i - 1];
        }

        for(int i = mid + 1; i < n; i++){
            int m = (n - 2 * (i - mid)) / 2;
            sum += board[i][mid + m] - board[i][mid - m - 1];
        }
        cout << "#" << cur << " " << sum << "\n";
    }
}

/*
1
1
3

1
3
132
254
021

1
5
14054
44250
02032
51204
52212

1
5
05023
33212
12511
23321
24132
*/