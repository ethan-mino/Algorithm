#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int arr[3];

    if(a > b) {
        if(a > c){
            arr[2]=a;
            if(b > c){
                arr[1]=b;
                arr[0]=c;
            }else{
                arr[1]=c;
                arr[0]=b;
            }
        }
        else {
            arr[2]=c;
            arr[1]=a;
            arr[0]=b;
        }
    }else{
        if(b > c){
            arr[2]=b;
            if(a > c){
                arr[1]=a;
                arr[0]=c;
            }else{
                arr[1]=c;
                arr[0]=a;
            }
        }
        else{
            arr[2]=c;
            arr[1]=b;
            arr[0]=a;
        }
    }
    for(auto n : arr) cout << n << " ";
}

/* 빠킹독 코드
    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c; // 입력
    cin >> a >> b >> c;
    int d, e, f; // 크기 순으로 출력할 세 수
    d = min({a,b,c});
    f = max({a,b,c});
    e = a+b+c-d-f;
    cout << d << ' ' << e << ' ' << f;
    }
*/