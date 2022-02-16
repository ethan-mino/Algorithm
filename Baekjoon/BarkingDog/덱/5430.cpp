#include <bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int dat[2 * MAX + 1];
int head = MAX, tail = MAX;
int order = 0;  // 0이면 왼쪽에서 오른쪽, 1이면 오른쪽에서 왼쪽

void push_back(int n){
    if(order){  // 역순
        dat[--tail] = n;
    }else{
        dat[tail++] = n;
    } 
}

void pop_front(){
    if(order){  // 역순
        head--;
    }else{
        head++;
    }  
}

int size(){
    if(order)   // 역순
        return head - tail;
    else
        return tail - head;
}

int empty(){
    if(size() == 0)
        return 1;
    else 
        return 0;
}

void reverse(){
    int temp = head;    // head, tail swap

    if(order){  // 역순 -> 정순
        head = tail + 1;
        tail = temp + 1;
    }else{  // 정순 -> 역순
        head = tail - 1;
        tail = temp - 1;
    }

    order = (order) ? 0 : 1;
}

void printDeque(){
    cout << "[";
    if(order){  // 역순
        for(int i = head; i > tail; i--){
            cout << dat[i];
            if(i != tail + 1)
                cout << ",";
        }
    }else{
        for(int i = head; i < tail; i++){
            cout << dat[i];

            if(i != tail - 1)
                cout << ",";
        }
    }
    cout << "]\n";
}

void parse(string & s){
    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    char str[300000];
    strcpy(str, s.c_str());

	char * token = strtok(str, ",");

	while (token) {
        push_back(atoi(token));
		token = strtok(NULL, ",");
	}
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--){
        string op;
        cin >> op;

        int c;
        cin >> c;

        string s;
        cin >> s;
        
        fill(dat, dat + (2 * MAX + 1), 0);
        order = 0;
        head = MAX, tail = MAX;

        parse(s);
        bool error = false;

        for(int i = 0; i < op.length(); i++){
            if(op[i] == 'R'){
                reverse();
            }else if(op[i] == 'D'){
                if(empty()) {error = true; break;}
                else pop_front();
            }
        }

        if(error) cout << "error" << "\n";
        else printDeque();
    }
}

/*
    void parse(string& tmp, deque<int>& d){
    int cur = 0;
    for(int i = 1; i+1 < tmp.size(); i++)
    {
        if(tmp[i] == ','){
        d.push_back(cur);
        cur = 0;
        }
        else{
        cur = 10 * cur + (tmp[i] - '0');
        }
    }
    if(cur != 0)
        d.push_back(cur);
    }

    void print_result(deque<int>& d){
    cout << '[';
    for(int i = 0; i < d.size(); i++)
    {
        cout << d[i];
        if(i+1 != d.size())
        cout << ',';
    }
    cout << "]\n";
    }

    int t;
    int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        deque<int> d;
        int rev = 0;
        int n;
        bool isWrong = false;
        string query, tmp;
        cin >> query;
        cin >> n;
        cin >> tmp;
        parse(tmp, d);
        for(char c : query)
        {
        if(c == 'R')
            rev = 1 - rev;
        else{
            if(d.empty()){
            isWrong = true;
            break;
            }
            if(!rev) d.pop_front();
            else d.pop_back();
        }
        }
        if(isWrong)
        cout << "error\n";
        else{
        if(rev) reverse(d.begin(), d.end());
        print_result(d);
        }
    }
    }
*/