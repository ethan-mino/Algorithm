// Created by 길민호 on 2022/10/05.
#include <bits/stdc++.h>

using namespace std;

int height[100100];
int prefix[100100];

int main() {
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> height[i];

    for(int i = 0; i < m; i++){
        int a, b, w; cin >> a >> b >> w;
        prefix[a - 1] += w;
        prefix[b] -= w;
    }

    for(int i = 1; i <= n; i++)
        prefix[i] += prefix[i - 1];

    for(int i = 0; i < n; i++)
        cout << height[i] + prefix[i] << " ";
}

