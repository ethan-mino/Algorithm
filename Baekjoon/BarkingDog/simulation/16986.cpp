#include <bits/stdc++.h>
using namespace std;

int table[9][9];
int b[20], c[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> table[i][j];

    vector<int> a;

    for(int i = 1; i <= n; i++) a.push_back(i); // 지우가 낼 손동작 순서
    for(int i = 0; i < 20; i++) cin >> b[i];    // 경희가 낼 손동작 순서
    for(int i = 0; i < 20; i++) cin >> c[i];    // 민호가 낼 손동작 순서
    
    int ans = 0;
    do{
        int ho[3] = {0, 0, 0};  // 지우, 경희, 민호가 낼 손동작 idx
        int s[3] = {0, 0, 0};   // 지우, 경희, 민호의 승수
        int win = -1; // 우승자
        int cur = 0, nx = 1;    // cur와 nx가 경기
        deque<int> order = {2};   // 경기 진행 순서, 0은 지우, 1은 경희, 2는 민호 

        while(true){
            int ch, nh; // cur가 낼 손동작, nh가 낼 손동작
            if(cur == 0) ch = a[ho[0]++]; else if(cur == 1) ch = b[ho[1]++]; else ch = c[ho[2]++];
            if(nx == 0) nh = a[ho[0]++]; else if(nx == 1) nh = b[ho[1]++]; else nh = c[ho[2]++];

            int r = table[ch-1][nh-1];
            if(r == 0 || (r == 1 && cur < nx)){ // nx가 이긴 경우
                s[nx]++;
                order.push_back(cur);
                cur = nx; nx = order.front(); 
                order.pop_front(); 
            }else if(r == 2 || (r == 1 && nx < cur) ){    // cur가 이긴 경우
                s[cur]++;
                order.push_back(nx);
                nx = order.front(); 
                order.pop_front(); 
            }
            int mi = max_element(s, s+3) - s;   // 승수가 가장 높은 사람의 idx

            if(s[mi] == k) {win = mi; break;}   // 우승을 위해 필요한 승수가 채워진 경우
            if(ho[0] >= n) break;   // 지우가 더이상 낼 손동작이 없는 경우
        }
        // 게임 종료 후
        if(win == 0) {ans = 1; break;}  // 지우가 이긴 경우
    }while(next_permutation(a.begin(), a.end()));   // 지우의 손동작 순서의 각 경우의 수에 대해 게임 진행
    cout << ans;
}