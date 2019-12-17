#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int addr[100001];
int nextEle[100001];
int toInt(string s){
    int num=0;
    if(s=="-1") return 100000;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
string toString(int n){
    string s="";
    s+=n/10000+'0';
    s+=n%10000/1000+'0';
    s+=n%1000/100+'0';
    s+=n%100/10+'0';
    s+=n%10+'0';
    return s;
}
int main(int argc, char const *argv[])
{
    string start,from,to;int n,k,val;
    vector<int> v;
    cin>>start>>n>>k;
    int org=toInt(start);
    for (int i = 0; i < n; i++)
    {
        cin>>from>>val>>to;
        addr[toInt(from)]=val;
        nextEle[toInt(from)]=toInt(to);
    }
    while (org!=100000)
    {
        if(addr[org]<0){
            v.push_back(org);
            org=nextEle[org];
        }
        else
            org=nextEle[org];
    }
    org=toInt(start);
    while (org!=100000)
    {
        if(addr[org]<=k && addr[org]>=0){
            v.push_back(org);
            org=nextEle[org];
        }
        else org=nextEle[org];
    }
    org=toInt(start);
    while (org!=100000)
    {
        if(addr[org]>k){
            v.push_back(org);
            org=nextEle[org];
        }
        else org=nextEle[org];
    }
    for (int i = 0; i < v.size(); i++)
    {
        if(i==v.size()-1) std::cout << toString(v[i])<<" "<<addr[v[i]]<<" "<<-1 << std::endl;
        else std::cout << toString(v[i])<<" "<<addr[v[i]]<<" "<<toString(v[i+1]) << std::endl;
    }
    return 0;
}
