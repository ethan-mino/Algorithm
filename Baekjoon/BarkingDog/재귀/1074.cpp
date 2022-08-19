#include <bits/stdc++.h>
using namespace std;

int search(int n, int r, int c){
    if(n == 1) {return (2*r) + c;}

    int p = pow(2, n);

    if(r < p/2 && c < p/2){ // 좌상단 부분배열에서 탐색
        return search(n - 1, r, c);
    }else if(r < p/2 && c >= p/2){   // 우상단 부분배열
        return search(n - 1, r, c - p/2) + pow(2, 2*n - 2);
    }else if(r >= p/2 && c < p/2){  // 좌하단 부분배열
        return search(n - 1, r - p/2, c) + pow(2, 2*n - 2) * 2;
    }else if(r >= p/2 && c >= p/2){  // 우하단 부분배열
        return search(n - 1, r - p/2, c - p/2) + pow(2, 2*n - 2) * 3;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;

    cout << search(n, r, c) << "\n";
}


