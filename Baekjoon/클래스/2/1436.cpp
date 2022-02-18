#include <bits/stdc++.h>
using namespace std;


int d(int num, int digit){
    int cnt = 0;
    int divisor = 1;
    bool devil = false;

    for(int i = 0; i < digit; i++){
        if(num / divisor % 10 == 6) cnt++;
        else cnt = 0;
        
        if(cnt == 3) devil = true;
        divisor *= 10;
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int th = 1;
    int num = 666;
    int digit = 3;

    while(true){
        if(n == th){
            cout << num << "\n";
            break;
        }
        else{
            int cnt = 0;
            int divisor = 1;
            bool devil = false;
            num++;

            for(int i = 0; i < digit; i++){
                if(num / divisor % 10 == 6) cnt++;
                else cnt = 0;
                
                if(cnt == 3) devil = true;
                divisor *= 10;
            }
            
            if(devil) th++;
            if(num / divisor >= 1) digit++;
        }
    }
}

// 754 10 100
// 754 / 100 % 10 -> 7
// 754 / 10 % 10 -> 5 
// 754 / 1% 10