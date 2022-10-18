// Created by 길민호 on 2022/10/13.

#include <bits/stdc++.h>

using namespace std;

struct Node{
    int x, y, nodeNum;
};

map<int, vector<Node>> tree;
int rootLayer = -1, lastLayer = 10000; // root 노드의 y좌표
int minX = INT_MAX, maxX = -1;
vector<int> layers;

Node find(int layer, int start, int end){
    vector<Node> curLayerNodes = tree[layer];
    for(int i = 0; i < curLayerNodes.size(); i++){
        Node curNode = curLayerNodes[i];
        if(curNode.x >= start && curNode.x <= end){
            return curNode;
        }
    }

    return {-1, -1, -1};
}

// layer의 다음 layer를 찾는 함수
int nextLayer(int depth){
    if(depth + 1 < layers.size()){
        return layers[depth + 1];
    }else{
        return -1;
    }
}

// start, end는 x의 가능한 범위
void postOrder(int start, int end, int rootLayer, int depth, vector<int> & order){
    Node rootNode = find(rootLayer, start, end);

    if(rootNode.x != -1){
        int nxLayer = nextLayer(depth);

        if(nxLayer != -1){
            postOrder(start, rootNode.x - 1, nxLayer, depth + 1, order);
            postOrder(rootNode.x + 1, end, nxLayer, depth + 1, order);
        }
        order.push_back(rootNode.nodeNum);
    }
}

// start, end는 x의 가능한 범위
void preOrder(int start, int end, int rootLayer, int depth, vector<int> & order){
    Node rootNode = find(rootLayer, start, end);

    if(rootNode.x != -1){
        order.push_back(rootNode.nodeNum);
        int nxLayer = nextLayer(depth);
        if(nxLayer != -1){
            preOrder(start, rootNode.x - 1, nxLayer, depth + 1, order);
            preOrder(rootNode.x + 1, end, nxLayer, depth + 1, order);
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfos) {
    for(int nodeIdx = 0; nodeIdx < nodeinfos.size(); nodeIdx++){
        vector<int> node = nodeinfos[nodeIdx];

        rootLayer = max(rootLayer, node[1]);
        lastLayer = min(lastLayer, node[1]);
        minX = min(minX, node[0]);
        maxX = max(maxX, node[0]);
        layers.push_back(node[1]);
        tree[node[1]].push_back({node[0], node[1], nodeIdx + 1});
    }

    sort(layers.begin(), layers.end(), greater<>());
    layers.erase(unique(layers.begin(), layers.end()), layers.end());


    for(int layer = rootLayer; layer >= lastLayer; layer--){
        sort(tree[layer].begin(), tree[layer].end(), [] (Node n1, Node n2) -> bool {
            return n1.x < n2.x;
        });
    }

    Node rootNode = tree[rootLayer][0];
    vector<int> preOrderVector, postOrderVector;
    preOrder(minX, maxX, rootLayer, 0, preOrderVector);
    postOrder(minX, maxX, rootLayer, 0, postOrderVector);

    return {preOrderVector, postOrderVector};
}