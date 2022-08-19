#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int min = 101;

    for (int i = 0; i < 7; i ++){
        int n;
        cin >> n ;

        if(n & 1){
            sum += n;    

            if(min > n)
                min = n;
        }
    }
    if(sum == 0){
        cout << -1;
    }
    else{
        cout << sum << "\n" <<  min;
    }

}

/*
    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x, odd = 0, sum = 0, min = 100;

    for (int i = 0; i < 7; i++) {
        cin >> x;

        if (x & 1) {
        odd += 1;
        sum += x;

        if (x < min) {
            min = x;
        }
        }
    }

    if (odd) cout << sum << "\n" << min;
    else cout << "-1";
    }
*/