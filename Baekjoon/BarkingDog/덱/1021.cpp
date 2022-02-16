#include <bits/stdc++.h>
using namespace std;


/* 내가 품
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int > v;

    for(int i = 0; i < m; i++){
        int c; cin >> c;
        v.push_back(c);
    }

    int cnt = 0;

    for(int i =0; i < m; i++){
        if(v[i] <= n / 2 + 1){    // 큐 중간의 왼쪽 부분에 해당 원소가 있는 경우
            cnt += v[i] - 1; // 2번 연산

            for(int j = i + 1; j < m; j++){ // 다음 원소들의 idx 수정
                if(v[j] < v[i]){  // 다음 원소가 현재 원소보다 왼쪽에 있었을 때
                    v[j] = n - (v[i] - v[j]);
                }else{  // 다음 원소가 현재 원소보다 오른쪽에 있었을 때
                    v[j] -= v[i];
                }
            }
        }else{  // 큐 중간의 오른쪽 부분에 해당 원소가 있는 경우
            cnt += n - v[i] + 1; // 3번 연산

            for(int j = i + 1; j < m; j++){
                if(v[j] < v[i]){  // // 다음 원소가 현재 원소보다 왼쪽에 있었을 때
                    v[j] += n - v[i];
                }else{  // // 다음 원소가 현재 원소보다 오른쪽에 있었을 때
                    v[j] = (v[j] - v[i]);
                }
            }
        }
        n--;
    }

    cout << cnt;
}*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> d;

    int n, m;
    cin >> n >> m;

    vector<int> v;

    for(int i = 0; i < m; i++){
        int c;
        cin >> c;
        v.push_back(c);
    }

    for(int i = 1; i <= n; i++){
        d.push_back(i);
    }

    int cnt = 0;

    for(int i = 0; i < m; i++){
        int idx;

        for(int j = 0; j < d.size(); j++){
            if(d[j] == v[i])
                idx = j;
        }

        if(idx <= d.size() / 2){
            cnt += idx;
            while(idx--){
                d.push_back(d.front());
                d.pop_front();
            }
        }else{
            cnt += d.size() - idx;
            int size = d.size();

            for(int j = 0; j < size - idx; j++){
                d.push_front(d.back());
                d.pop_back();
            }
        }
        d.pop_front();
    }

    cout << cnt;
}

/*
    int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    deque<int> DQ;
    for (int i = 1; i <= n; i++) DQ.push_back(i);
    int ans = 0;
    while (m--) {
        int t;
        cin >> t;
        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // idx : t가 있는 위치
        while (DQ.front() != t) {
        if (idx < DQ.size() - idx) { 
            DQ.push_back(DQ.front());
            DQ.pop_front();
        }
        else {
            DQ.push_front(DQ.back());
            DQ.pop_back();
        }
        ans++;
        }
        DQ.pop_front();
    }
    cout << ans;
    }

    // 20번째 줄에서, 지금은 idx가 항상 DQ.size()보다 작아서 문제가 없지만
    // DQ.size()는 unsigned int(or unsigned long long)이기
    // 때문에 만약 idx가 DQ.size()보다 컸다면 overflow가 발생해
    // 의도한대로 동작하지 않을 수 있음을 인지해야 함. 그래서 size()로
    // 받아온 값에 대해서는 안전하게 (int)DQ.size() 로 항상 형변환을
    // 하는 것도 괜찮음.
*/