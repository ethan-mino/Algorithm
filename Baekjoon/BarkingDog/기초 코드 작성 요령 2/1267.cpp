#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    int t1 = 0;
    int t2 = 0;

    while(n--){
        int c;
        cin >> c;
        
        t1 += ((c / 30) + 1) * 10;
        t2 += ((c / 60) + 1) * 15;
    }

    if(t1 == t2){
        cout << "Y M " << t1;
    }else{
        if(t1 > t2){
            cout << "M " << t2;
        }else{
            cout << "Y " << t1;
        }
    }

}

/*
    int phone[10000], Y, M;

    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    int N;
    cin >> N;
        
    for(int n = 0; n < N; n++) cin >> phone[n];
        
    for(int n = 0; n < N; n++) Y += ((phone[n] / 30) + 1) * 10;
        
    for(int n = 0; n < N; n++) M += ((phone[n] / 60) + 1) * 15;
        
    if(Y < M) cout << "Y " << Y;
    else if(Y > M) cout << "M " << M;
    else cout << "Y M " << Y;
    }
*/