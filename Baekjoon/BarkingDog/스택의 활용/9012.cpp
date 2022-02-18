#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        string str;
        cin >> str;

        stack<int> s;
        bool flag = true;

        for(auto c : str){
            if(c == '(')
                s.push(c);
            else{
                if(!s.empty() && s.top() == '('){
                    s.pop();
                }else{
                    flag = false;
                    break;
                }
            }
        }

        if(!s.empty())
            flag = false;

        if(flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}