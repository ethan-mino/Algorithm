#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // multiset<int> s = {1, 2, 3};
    // auto iter = s.end();
    // iter--;
    // cout << (*iter) << "\n";
    // s.erase(iter);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        multiset<int> s;
        for(int i = 0; i < n; i++){
            char op; cin >> op;
            int target; cin>> target;

            if(op == 'I'){
                s.insert(target);
            }else {
                if(s.size() > 0){
                    if(target == -1){
                        // 최솟값 삭제
                        s.erase(s.begin());
                    }else{
                        // 최댓값 삭제
                        s.erase(prev(s.end()));
                    }
                }
            }
        }      
        if(s.size() == 0){
            cout << "EMPTY" << "\n";
        } else{
            cout << *prev(s.end()) << " " << *s.begin() << "\n";
        }
    }
}