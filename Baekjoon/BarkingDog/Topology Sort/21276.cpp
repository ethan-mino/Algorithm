#include <bits/stdc++.h>
using namespace std;

#define MAX 1010
int in[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    map<string, int> pton; // 사람 이름과 번호를 매핑
    map<int, string> ntop;
    for(int i = 1; i <= n; i++){
        string name; cin >> name;
        pton[name] = i;
        ntop[i] = name;
    }

    int m; cin >> m;
    vector<vector<int>> linked(n + 1);
    for(int i = 0; i < m; i++){
        string u, v; cin >> u >> v;
        in[pton[u]]++;
        linked[pton[v]].push_back(pton[u]);
    }

    vector<string> anc;
    for(int v = 1; v <= n; v++)
        if(in[v] == 0) anc.push_back(ntop[v]);

    sort(anc.begin(), anc.end());
    cout << anc.size() << "\n";
    for(auto a : anc) cout << a << " ";
    cout << "\n";

    for(auto people : pton){
        int v = people.second;
        vector<string> des;
        int c_in[MAX];
        memcpy(c_in, in, sizeof(c_in));

        // 조상을 한 단계씩 지움
        // 자식의 수를 계산하려는 사람인 경우, 연결된 자손 중, indegree가 0인 사람이 자식임
        queue<int> zero;
        for(int i = 1; i <= n; i++)
            if(c_in[i] == 0) zero.push(i);
        
        while(!zero.empty()){
            int cur = zero.front(); zero.pop();

            for(auto nxt : linked[cur]){
                c_in[nxt]--;
                if(c_in[nxt] == 0) {
                    zero.push(nxt);
                    if(cur == v) des.push_back(ntop[nxt]);
                }
            }
        }

        sort(des.begin(), des.end());
        cout << people.first << " " << des.size() << " ";
        for(auto d : des) cout << d << " ";
        cout << "\n";
    }
}