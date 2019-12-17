#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <vector>
using namespace std;

struct Node{
    string addr;
    int data;
    string next;
    void show(){
        std::cout << this->addr<<" "<<this->data<<" "<<this->next << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    int n,k;
    string addr;
    cin>>addr>>n>>k;
    string address;int data;string des;
    map<string,Node> map;
    for (int i = 0; i < n; i++)
    {
        cin>>address>>data>>des;
        Node node={address,data,des};
        map[address]=node;
    }
    vector<Node> v;
    while (addr!="-1")
    {
        v.push_back(map.find(addr)->second);
        addr=map.find(addr)->second.next;
        if(v.size()==k){
            string temp=v[k-1].next;
            for (int i = k-1; i >0; i--){
                v[i].next=v[i-1].addr;
                v[i].show();
            }
            v[0].next=temp;
            v[0].show();
            addr=temp;
            v.clear();
        }
    }
    for (int i = 0; i < v.size(); i++){
        v[i].show();
    }
    return 0;
}
