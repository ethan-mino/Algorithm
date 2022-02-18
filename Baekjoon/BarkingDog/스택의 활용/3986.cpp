#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt = 0;

    while(n--){
        string str;
        cin >> str;

        stack<int> s;
        
        for(auto c : str){
            if(!s.empty() && s.top() == c){
                s.pop();
            }else{
                s.push(c);
            }
        }

        if(s.empty()) cnt++;
    }

    cout << cnt;
}
