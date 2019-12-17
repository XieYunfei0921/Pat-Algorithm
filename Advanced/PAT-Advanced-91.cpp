#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Node{
    int type;
    int id;
    int score;
    bool vis;
    friend bool operator<(Node n1,Node n2){
        if(n1.score==n2.score && n1.type==n2.type) return n1.id>n2.id;
        if(n1.score==n2.score) return n1.type>n2.type;
        return n1.score<n2.score;
    }
};
int main(int argc, char const *argv[]){
    return 0;
}
