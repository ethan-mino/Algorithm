#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0 ; i < 3; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int sum = a + b + c + d;

    /*
        vector<int> v;

        for (int i = 0; i < 4; i++){
            int input;
            cin >> input;
            v.push_back(input);
        }
        int sum = accumulate(v.begin(), v.end(), 0);
    */
        if( sum == 0){
            cout << "D" << "\n";
        }else if(sum == 1){
            cout << "C" << "\n";
        }else if(sum == 2){
            cout << "B" << "\n";
        }else if(sum == 3){
            cout << "A" << "\n";
        }else{
            cout << "E" << "\n";
        }
    }
}

/*
    int result, input;
    string res = "DCBAE";

    int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
        
    for(int r = 0; r < 3; r++) {
        result = 0;
        for(int c = 0; c < 4; c++) {
        cin >> input;
        result += input;
        }
        cout << res[result] << '\n';
    }
    }
*/