// 소요 시간 : 1시간 20분
#include <bits/stdc++.h>
using namespace std;

int s[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;    
    for(int i = 0; i < n; i++) cin >> s[i]; // 용액 입력 받음

    int m = INT_MAX;    // 0에 가장 가까운 특성값
    pair<int, int> selected;    // 혼합했을 때, 0에 가장 가까운 용액
    for(int i = 0; i < n; i++){ // 모든 용액에 대해, 혼합했을 때 0에 가장 가까운 두 번째 용액을 찾음
        int s2 = s[i] * -1; // s[i]와 섞었을 때 0이 되는 특성값
        
        bool exist = binary_search(s + (i + 1), s + n, s2); // s2를 배열 내에서 찾음
        if(exist){  // 찾은 경우
            selected = {min(s[i], s2), max(s[i], s2)};  
            break;  // 더이상 찾을 필요 없음
        }else{
            int idx = lower_bound(s + (i + 1), s + n, s2) - s;  // S2를 배열에 넣었을 때, 정렬이 유지되는 가장 작은 idx를 찾음
            
            // 단, 첫번째 용액과 두번째 용액이 같으면 안됨
            if(i != idx - 1 &&  m > abs(s[i] + s[idx - 1])){    // m보다 s[i] + s[idx - 1]가 0에 가깝다면
                selected = {min(s[i], s[idx - 1]), max(s[i], s[idx - 1])};
                m = abs(s[i] + s[idx - 1]);
            }

            if(idx < n){
                if(i != idx && m > abs(s[i] + s[idx])){ // m보다 s[i] + s[idx]가 0에 가깝다면
                    //cout << "3\n";
                    selected = {min(s[i], s[idx]), max(s[i], s[idx])};
                    m = abs(s[i] + s[idx]);
                }
            }
        }
    }

    cout << selected.first << " " << selected.second << "\n";
}

// 0에 가장 가까운 특성값을 만들어낼 수 있는 두 용액의 합
