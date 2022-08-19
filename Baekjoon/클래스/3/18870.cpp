#include <bits/stdc++.h>
using namespace std;

struct pos {int x1, x2, idx;};   // x1은 기존 좌표, x2는 새로운 좌표, idx는 입력 받은 순서를 나타냄
bool cmp1(pos p1, pos p2){return  p1.x1 < p2.x1;}   // 압축 전 좌표를 기준으로 정렬
bool cmp2(pos p1, pos p2){return  p1.idx < p2.idx;} // 입력 받은 순서를 기준으로 정렬

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<pos> x;
    for(int i = 0; i < n; i++) {    
        int c; cin >> c;
        x.push_back({c, 0, i});
    }

    sort(x.begin(), x.end(), cmp1); // 압축 전 좌표를 기준으로 정렬
    
    x[0].x2 = 0;    // 가장 작은 좌표를 시작점으로 잡음
    for(int i = 1; i < n;){
        if(x[i - 1].x1 == x[i].x1) x[i].x2 = x[i - 1].x2;   // 이전 좌표와 좌표가 같은 경우 압축한 결과가 같도록 함
        else x[i].x2 = x[i - 1].x2 + 1; // 이전 좌표보다 클 경우, 이전 좌표의 압축 결과 + 1
        i++;
    }

    sort(x.begin(), x.end(), cmp2); // 입력 받은 순서를 기준으로 정렬
    for(auto c : x) cout << c.x2 << " ";
}   
