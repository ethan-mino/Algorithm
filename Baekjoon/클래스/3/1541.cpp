#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> num;
    string str; cin >> str;
    for(int i = 0; i < str.size();){    // 문자열에서 숫자를 뽑음
        if(i == 0 || str[i] == '+' || str[i] == '-'){   // 첫 번째 문자이거나 연산자인 경우
            string t = "";
            do{
                t+=str[i];  // t에 붙여줌
                i++;    // 인덱스 한 칸 이동
            }while(i < str.size() && str[i] != '+' && str[i] != '-');   // 다음 연산자를 만나거나 문자열의 끝인 경우 종료

            num.push_back(stoi(t)); // 숫자를 저장하는 벡터에 push
        }
    }

    int t = 0;
    for(int i = 0; i < num.size();){
        if(num[i] < 0){ // 음수 인 경우
            t += num[i++];  // 음수를 더해줌
            while(i < num.size() && num[i] >= 0)    // 다음 숫자가 양수일 경우 음수로 바꿔준 다음 더해줌
                t+= -1 * num[i++];
        }else{  // 양수인 경우 더해줌
            t += num[i++];
        }
    }
    cout << t;
}   