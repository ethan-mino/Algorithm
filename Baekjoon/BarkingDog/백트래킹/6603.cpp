// Authored by : rlfalsgh95
// https://www.acmicpc.net/problem/6603

#include <bits/stdc++.h>
using namespace std;

int k; 
int input[49], selected[49];
bool isused[49];
const int NUM = 6;

void back(int r, int th){
    if(th == NUM + 1){
        for(int i = 0; i < NUM; i++) cout << selected[i] << " ";
        cout << "\n";
    }else{
        for(int i = r; i < k; i++){
            if(!isused[i]){
                isused[i] = true; selected[th - 1] = input[i];
                back(i + 1, th + 1);
                isused[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> k;
        if(!k) break;

        fill(input, input + 49, 0);
        fill(selected, selected + 49, 0);

        for(int i = 0; i < k; i++) cin >> input[i];
        
        back(0, 1);
        cout << "\n";
    }
}

/*
7 1 2 3 4 5 6 7
0

8 1 2 3 5 8 13 21 34
0

*/