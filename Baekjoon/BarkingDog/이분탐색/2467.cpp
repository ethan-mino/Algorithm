#include <bits/stdc++.h>
using namespace std;

int s[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];

    int m = INT_MAX;
    pair<int, int> selected;
    for(int i = 0; i < n; i++){
        int s2 = s[i] * -1; // s[i]와 섞었을 때 특성값이 0이 되는 용액
        
        bool exist = binary_search(s + (i + 1), s + n, s2);
        if(exist){  // 찾은 경우
            selected = {min(s[i], s2), max(s[i], s2)};
            break;
        }else{
            int idx = lower_bound(s + (i + 1), s + n, s2) - s;

            if(i != idx - 1 &&  m > abs(s[i] + s[idx - 1])){
                selected = {min(s[i], s[idx - 1]), max(s[i], s[idx - 1])};
                m = abs(s[i] + s[idx - 1]);
            }

            if(idx < n){
                if(i != idx && m > abs(s[i] + s[idx])){
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
