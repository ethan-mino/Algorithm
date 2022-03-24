#include <bits/stdc++.h>
using namespace std;

int cube[3][3][3];


void rotate(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n; cin >> t;

    deque<vector<char>> q1, q2, q3; // 3, 1, 5, 6에 해당
    deque<vector<char>> q4, q5, q6;  // 2, 1, 4, 6에 해당
    deque<vector<char>> q7, q8, q9; // 2, 3, 4, 5에 해당

    char xc[4] =  {'g', 'w', 'b', 'y'};
    for(int i = 0; i < 4; i++){
        q1.push_back({xc[i], xc[i], xc[i]});
        q2.push_back({xc[i], xc[i], xc[i]});
        q3.push_back({xc[i], xc[i], xc[i]});
    }

    char yc[4] =  {'o', 'w', 'r', 'y'};
    for(int i = 0; i < 4; i++){
        q4.push_back({yc[i], yc[i], yc[i]});
        q5.push_back({yc[i], yc[i], yc[i]});
        q6.push_back({yc[i], yc[i], yc[i]});
    }
    char zc[4] = {'g', 'r', 'b', 'o'};
    for(int i = 0; i < 4; i++){
        q7.push_back({zc[i], zc[i], zc[i]});
        q8.push_back({zc[i], zc[i], zc[i]});
        q9.push_back({zc[i], zc[i], zc[i]});
    }

    vector<deque<vector<char>>> x = {q1, q2, q3};
    vector<deque<vector<char>>> y = {q4, q5, q6};
    vector<deque<vector<char>>> z = {q7, q8, q9};

//   2
// 3 1 5 6
//   4
//   6

    while(t--){
        cin >> n;
        while(n--){
            char op, dir;
            cin >> op >> dir;
            deque<vector<char>> cur;

            if(op == 'U' || op == 'D'){  // 윗/뒷 면
                if(op == 'U') cur = q7; else cur = q9;

                if(dir == '+') {cur.push_back(cur.front()); cur.pop_front();}
                else {cur.push_front(cur.back()); cur.pop_back();}
                // 윗면 회전
                for(int i =0; i < 3; i++){  // 2, 1, 4, 6의 2, 4의 동기화
                    
                }

                for(int i = 0; i < 3; i++){ // 3, 1, 5, 6의 

                }
            }else if(op == 'L' || op == 'F'){  // 왼쪽/오른쪽 면
                if(op == 'L') cur = q4; else cur = q6;

                if(dir == '+') {cur.push_back(cur.front()); cur.pop_front();}
                else {cur.push_front(cur.back()); cur.pop_back();}
                // 면 회전
                for(int i =0; i < 3; i++){  // 2, 1, 4, 6의 2, 4의 동기화
                    
                }

                for(int i = 0; i < 3; i++){ // 3, 1, 5, 6의 

                }
            }else if(op == 'F' || op == 'B'){  // 앞/뒷 면
                if(op == 'F') cur = q3; else cur = q1;

                if(dir == '+') {cur.push_back(cur.front()); cur.pop_front();}
                else {cur.push_front(cur.back()); cur.pop_back();}
                
                for(int i =0; i < 3; i++){  
                    
                }

                for(int i = 0; i < 3; i++){ 

                }
            }
        }

        for(auto r : y){  // 윗 면 출력
            for(int i = 0; i < 3; i++)
                cout << r[1][i];
            cout << "\n";
        }
    }
}
