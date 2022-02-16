#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[21];

    for(int i = 1; i < 21; i++)
        arr[i] = i;
    
    for(int i = 0; i < 10; i++){
        int a, b;
        cin >> a >> b;

        int j = ((b - a) + 1) / 2; 

        while(j--){
            int temp = arr[a + j];
            arr[a + j] = arr[b - j];
            arr[b - j] = temp;
        }

    }

    for(int i = 1; i < 21; i++) cout << arr[i] << " ";
}


/*
    int num[21];

    // 카드를 역순으로 놓는 함수
    void reverse(int a, int b){
    for(int i = 0; i < (b - a + 1) / 2; i++)
        swap(num[a+i], num[b-i]);
    }

    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    for(int i = 1; i <= 20; i++) num[i] = i;
        
    for(int i = 1; i <= 10; i++) {
        int a, b;
        cin >> a >> b;        
        reverse(a, b);
    }
        
    for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
    }
*/

/*
    int num[21];

    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    for(int i = 1; i <= 20; i++) num[i] = i;
        
    for(int i = 1; i <= 10; i++) {
        int a, b;
        cin >> a >> b;        
        reverse(num+a, num+b+1);
    }
        
    for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
    }
*/