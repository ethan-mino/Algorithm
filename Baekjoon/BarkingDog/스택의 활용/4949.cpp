#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        string s;
        getline(cin, s);

        stack<char> stack;
        bool flag = true;

        if(s == "."){
            break;
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '[' || s[i] == '(' ){ //  여는 괄호
                stack.push(s[i]);
            }else if(s[i] == ']' || s[i] == ')'){    // 닫는 괄호
                if(stack.empty()){
                    flag = false;
                    break;
                }
                    
                char t = stack.top();

                if((t == '(' && s[i] == ')') ||
                (t == '[' && s[i] == ']')) {
                    stack.pop();
                }else{
                    flag = false;
                    break;
                }
            }
        }

        if(!stack.empty()) flag = false;

        if(flag) cout << "yes";
        else cout << "no";
        cout << "\n";
    }
}
