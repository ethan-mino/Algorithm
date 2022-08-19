#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        v.push_back(c);
    }

    stack<pair<int, int> > s;
    stack<int> s1;

    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && v[i] >= s.top().first){
            s.pop();
        }

        if(s.empty())
            s1.push(-1);
        else
            s1.push(s.top().first);
        s.push(pair<int, int>(v[i], i));

    }

    for(int i = 0; i < n; i++) {
        cout << s1.top() << " ";
        s1.pop();
    }

}
