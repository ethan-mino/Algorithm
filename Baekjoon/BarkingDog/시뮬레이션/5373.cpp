#include <bits/stdc++.h>
using namespace std;

// iter은 시계 방향으로의 회전 횟수, 3이면 시계 방향으로 3번 회전하여 반시계 방향으로 회전
void rotate(vector<deque<vector<char>>>& v, int th, int iter){  
    for(int i = 0; i < iter; i++){
        int arr[3][3] = {
            {v[2][th][0], v[1][th][0], v[0][th][0]}, 
            {v[2][th][1], v[1][th][1], v[0][th][1]}, 
            {v[2][th][2], v[1][th][2], v[0][th][2]}};

        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                v[j][th][k] = arr[j][k];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n; cin >> t;

    deque<vector<char>> q1, q2, q3, q4, q5, q6, q7, q8, q9; 

    char xc[4] =  {'g', 'y', 'b', 'w'};
    for(int i = 0; i < 4; i++){ // 3, 1, 5, 6에 해당
        q1.push_back({xc[i], xc[i], xc[i]});
        q2.push_back({xc[i], xc[i], xc[i]});
        q3.push_back({xc[i], xc[i], xc[i]});
    }

    char yc[4] =  {'o', 'y', 'r', 'w'};
    for(int i = 0; i < 4; i++){ // 2, 1, 4, 6에 해당
        q4.push_back({yc[i], yc[i], yc[i]});
        q5.push_back({yc[i], yc[i], yc[i]});
        q6.push_back({yc[i], yc[i], yc[i]});
    }
    char zc[4] = {'o', 'g', 'r', 'b'};
    for(int i = 0; i < 4; i++){ // 2, 3, 4, 5에 해당
        q7.push_back({zc[i], zc[i], zc[i]});
        q8.push_back({zc[i], zc[i], zc[i]});
        q9.push_back({zc[i], zc[i], zc[i]});
    }

    while(t--){
        vector<deque<vector<char>>> x = {q1, q2, q3}, y = {q4, q5, q6}, z = {q7, q8, q9};

        cin >> n;
        while(n--){
            char op, dir;
            cin >> op >> dir;
            
            if(op == 'U' || op == 'D'){  // 윗/뒷 면
                if(op == 'U') {
                    if(dir == '+') {z[0].push_back(z[0].front()); z[0].pop_front(); 
                    rotate(x, 3, 3); rotate(y, 3, 1);}
                    else {z[0].push_front(z[0].back()); z[0].pop_back(); 
                    rotate(x, 3, 1); rotate(y, 3, 3);}
                }else {
                    if(dir == '+') {z[2].push_front(z[2].back()); z[2].pop_back(); 
                    rotate(x, 1, 3); rotate(y, 1, 1);}
                    else {z[2].push_back(z[2].front()); z[2].pop_front();
                    rotate(x, 1, 1); rotate(y, 1, 3);}
                }
                
                for(int i =0; i < 3; i++){  
                    for(int j = 0; j < 3; j++)  // 2, 1, 4, 6의 2 동기화
                        y[i][0][j] = z[j][0][i];
                    for(int j = 0; j < 3; j++)  // 2, 1, 4, 6의 4 동기화
                        y[2 - i][2][2 - j] = z[j][2][i];    
                    for(int j = 0; j < 3; j++)  // 3, 1, 5, 6의 3 동기화
                        x[2 - i][0][j] = z[j][1][i];
                    for(int j = 0; j < 3; j++)  // 3, 1, 5, 6의 5 동기화
                        x[i][2][j] = z[2 - j][3][i];
                }
            }else if(op == 'L' || op == 'R'){  // 왼쪽/오른쪽 면
                if(op == 'L') {
                    if(dir == '+') {y[0].push_back(y[0].front()); y[0].pop_front(); 
                    rotate(x, 0, 3); rotate(z, 1, 3);}
                    else {y[0].push_front(y[0].back()); y[0].pop_back(); 
                    rotate(x, 0, 1); rotate(z, 1, 1);}
                }else {
                    if(dir == '+') {y[2].push_front(y[2].back()); y[2].pop_back(); 
                    rotate(x, 2, 3); rotate(z, 3, 3);}
                    else {y[2].push_back(y[2].front()); y[2].pop_front(); 
                    rotate(x, 2, 1); rotate(z, 3, 1);}
                }

                for(int i =0; i < 3; i++){  
                    for(int j = 0; j < 3; j++)  // 2, 3, 4, 5의 2 동기화
                        z[j][0][i] = y[i][0][j];
                    for(int j = 0; j < 3; j++)  // 2, 3, 4, 5의 4 동기화
                        z[j][2][i] = y[2 - i][2][2 - j];   
                    for(int j = 0; j < 3; j++) // 3, 1, 5, 6의 1 동기화
                        x[i][1][j] = y[j][1][i];
                    for(int j = 0; j < 3; j++) // 3, 1, 5, 6의 6 동기화
                        x[2 - i][3][2-j] = y[j][3][i];
                }
            }else if(op == 'F' || op == 'B'){  // 앞/뒷 면
                if(op == 'F') {
                    if(dir == '+') {x[2].push_back(x[2].front()); x[2].pop_front(); 
                    rotate(y, 2, 1); rotate(z, 2, 3);}
                    else {x[2].push_front(x[2].back()); x[2].pop_back(); 
                    rotate(y, 2, 3); rotate(z, 2, 1);}
                }else {
                    if(dir == '+') {x[0].push_front(x[0].back()); x[0].pop_back(); 
                    rotate(y, 0, 1); rotate(z, 0, 3);}
                    else {x[0].push_back(x[0].front()); x[0].pop_front(); 
                    rotate(y, 0, 3); rotate(z, 0, 1);}
                }
                
                for(int i =0; i < 3; i++){  
                    for(int j = 0; j < 3; j++){
                        for(int j = 0; j < 3; j++) // 2, 1, 4, 6의 1 동기화
                            y[j][1][i] = x[i][1][j];
                        for(int j = 0; j < 3; j++) // 2, 1, 4, 6의 6 동기화
                            y[j][3][i] = x[2 - i][3][2-j];
                        for(int j = 0; j < 3; j++)  // 2, 3, 4, 5의 3 동기화
                            z[j][1][i] = x[2 - i][0][j];
                        for(int j = 0; j < 3; j++)  // 2, 3, 4, 5의 5 동기화
                            z[2 - j][3][i] = x[i][2][j];
                    }
                }
            }
        }

        for(auto c : x){  // 윗 면 출력
            for(int i = 2; i >= 0; i--)
                cout << c[3][i];
            cout << "\n";
        }
    }
}


/*
1
1
L-

1
1
L+

1
1
R-

1
1
R+

1
1
F+

1
1
F-

1
1
B+

1
1
B-

1
1
U-

1
1
U+

1
1
D+

1
1
D-

2
1
L-
1
F+

3
1
L-
1
F+
1
B+

2
1
L-
1
F-

1
4
U- D- L+ R+

1
10
L- U- L+ U- L- U- U- L+ U+ U+

2
1
L-
2
F+ B+

1
2
L- U-

1
3
L- U- L+

1
2
L- F-

1
2
U- L-
*/