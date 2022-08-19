#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<char> orders;
    stack<int> s;
    queue<int> seq;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        seq.push(c);
    }

    bool success = true;
    int cur = 1;    // 현재 스택에 넣을 숫자
    while(cur <= n || s.size() != 0){
        while(cur <= n && (s.empty() || seq.front() != s.top())){ // 수열의 다음 숫자가 나올 때까지 push
            s.push(cur++);
            orders.push_back('+');
        }

        // 다음 숫자가 나온 경우
        if(s.top() != seq.front()) {
            success = false;
            break;
        }

        s.pop();
        seq.pop();

        orders.push_back('-');
    }

    if(success){
        for(auto order : orders) cout << order << "\n";
    }else{
        cout << "NO" << "\n";
    }
}