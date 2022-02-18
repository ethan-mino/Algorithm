#include <bits/stdc++.h>
using namespace std;

typedef struct{
    char c;
    int val;
}elem;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    vector<elem> v;

    cin >> str;
    
    int sum = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '['){ // 여는 괄호
            elem e; e.c = str[i]; e.val = 0;
            v.push_back(e);
        }else{  // 닫는 괄호
            if(v.empty()
            || (v.back().c == '(' && str[i] != ')')
            || v.back().c == '[' && str[i] != ']'){ // 스택이 비어있거나 짝이 맞지 않는 경우
                sum = 0; 
                break;  // 0 출력
            }else{
                int n;
                elem x = v.back(); 

                if(str[i] == ')') n = 2;    // 각 괄호에 따른 기본 값.
                else n = 3;

                if(v.size() == 1){  // 열린 괄호가 자신 밖에 없을 때
                    if(x.val == 0) sum += n;    // 하위 괄호가 없는 경우
                    else sum += n * x.val;  // 하위 괄호가 있는 경우
                }else{  // 상위에 열린 괄호가 있을 때
                    if(x.val == 0) v[v.size() - 2].val += n;    // 하위 괄호가 없는 경우, 기본 값을 더해줌
                    else v[v.size() - 2].val += n * x.val;  // 하위 괄호가 있는 경우, 상위 괄호의 값에 더해줌
                }

                v.pop_back();
            }
        }
    }

    if(!v.empty()) cout << 0;   // 짝이 맞지 않는 경우 0 출력
    else cout << sum;
}
