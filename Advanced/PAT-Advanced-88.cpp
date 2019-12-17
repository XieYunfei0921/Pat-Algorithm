#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
    M<=10000
    M 中选取k个节点,求k,使得两两节点路径和最小,输出最小路径
    HalfMan树
*/
struct Node{
    int fromId;
    int toId;
    int val;
};
int main(int argc, char const *argv[]){
    int n,m,k,temp;
    scanf("%d %d %d",&n,&m,&k);
    vector<Node> Adj[n+1];
    vector<int> list;
    for (int i = 0; i < m; i++){
        scanf("%d",&temp);
        list.push_back(temp);
    }
    // 求路径长度
    return 0;
}
