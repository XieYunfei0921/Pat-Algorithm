#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    string name;
    string id;
    int score;
    void show(){
        std::cout << this->name<<" "<<this->id << std::endl;
    }
};
bool cmp(Node n1,Node n2){
    return n1.score>n2.score;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    Node arr[n];
    for (int i = 0; i < n; i++)
    {
        string name,id;int score;
        cin>>name>>id>>score;
        Node n={name,id,score};
        arr[i]=n;
    }
    sort(arr,arr+n,cmp);
    arr[0].show();
    arr[n-1].show();
    return 0;
}
