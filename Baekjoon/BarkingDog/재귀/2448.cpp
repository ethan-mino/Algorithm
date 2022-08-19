#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

// 가장 하단의 별의 개수는 n / 3
// 가장 하단 줄의 수는 5 * (n/3) + (n/3-1)
// n의 최대값은 3072 -> 최하단 줄의 최대 길이는 5 * (3072 / 3) + (3072/3-1) = 6143

char board[3072][6143];

void star(pair<int, int> pos1, pair<int, int> pos2, pair<int, int> pos3){ // pos1은 삼각형 상단의 꼭짓점, pos2는 하단 좌측, pos3는 하단 우측
    if(pos3.y - pos2.y == 4){
        board[pos1.x][pos1.y] = '*';	// 첫번째 줄
        board[pos1.x + 1][pos2.y + 1] = '*'; board[pos1.x + 1][pos3.y - 1] = '*';	// 두번째 줄
        for(int i = pos2.y; i <= pos3.y; i++) board[pos2.x][i] = '*';	// 세번째 줄
    }else{
        star(pos1, {(pos1.x + pos2.x) / 2, (pos1.y + pos2.y)/2 + 1}, {(pos1.x + pos2.x) / 2, (pos1.y + pos3.y)/2}); // 상단의 삼각형
        star({(pos1.x + pos2.x) / 2 + 1, (pos2.y + pos1.y)/2}, {pos2}, {pos2.x, pos1.y - 1});   //   하단 좌측
        star({(pos1.x + pos2.x) / 2 + 1, (pos1.y + pos3.y)/2 + 1}, {pos2.x, pos1.y + 1}, {pos3});   // 하단 우측
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    fill(&board[0][0], &board[3071][6143], ' ');
    star({0, (5 * (n/3) + (n/3-1) - 1) / 2}, {n - 1, 0}, {n - 1, 5 * (n/3) + (n/3-1) - 1});

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 5 * (n/3) + (n/3-1); j++)
            cout << board[i][j];
        cout << "\n"; 
    }
}