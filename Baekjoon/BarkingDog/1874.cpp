#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;
    int cursor = 0;

    int arr[100001];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<char> t;

    for(int i = 1; i <= n; i++){
        s.push(i);

        t.push_back('+');

        while(!s.empty() && s.top() == arr[cursor]){
            cursor++;
            t.push_back('-');
            s.pop();
        }
    }

    if(!s.empty()){
        cout << "NO" << "\n";
    }
    else{
        for(auto c : t){
            cout << c << "\n";
        }
    }
}


/*
    int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> S;
    int cnt = 1;
    string ans;
    while (n--) {
        int t;
        cin >> t;
        while (cnt <= t) {
        S.push(cnt++);
        ans += "+\n";
        }
        if (S.top() != t) {
        cout << "NO\n";
        return 0;
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
    }
*/