#include <bits/stdc++.h>
using namespace std;

int input[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int c = 0;

    for(int i = 0; i < n; i++) cin >> input[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int num = input[i] + input[j] + input[k];
                if(num <= m && c < num)
                    c = num;
            }
        }
    }
    cout << c;
}

/*
5 30
29 25 3 2 1
*/