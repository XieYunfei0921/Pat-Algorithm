#include <iostream>
#include <string>
#include <queue>
#include <stdio.h>
using namespace std;
char table[20000];
struct Num{
    char c;
    Num* next;
    Num* last;
};

Num* init(char x){
    Num* nu=new Num;
    nu->c=x;
    nu->last=NULL;
    nu->next=NULL;
    return nu;
}
void push_back(Num* &n,char x){
    if(n->next==NULL){
        Num* nu=new Num;
        nu->c=x;
        nu->next=NULL;
        n->next=nu;
        nu->last=n;
        return;
    }
    push_back(n->next,x);
}
void push_front(Num* &n,char x){
    if(n->last==NULL){
        Num* nu=new Num;
        nu->c=x;
        nu->last=NULL;
        n->last=nu;
        nu->next=n;
        return;
    }
    push_front(n->last,x);
}

Num* searchNext(Num* &num,char x){
    if(num->c==x)
        return num;
    return searchNext(num->next,x);
}
Num* searchLast(Num* &num,char x){
    if(num->c==x)
        return num;
    return searchNext(num->last,x);
}

void step_back_move(Num* num){

}
Num* findRoot(Num* n){
    if(n->last==NULL)
        return n;
    return findRoot(n->last);
}

void show(Num* &num){
    if(num==NULL)
        return;
    cout<<num->c;
    show(num->next);
}
void move(Num* &num,int step,int index){

}
void reShow(string s){
    int val=0,index=0,sign=1;
    for (int i = s.length()-1; i >=1; i--)
    {
        if (s[i]=='-'){sign=-1;index=i-2;break;}
        if (s[i]=='+'){sign=1;index=i-2;break;}
    }
    for (int i = index+3; i <s.length(); i++)
        val=val*10+(s[i]-'0');
    val=sign*val;
    sign=(s[0]=='+')?1:-1;
    Num* num=init(s[1]);
    for (int i = 2; i <= index; i++)
        push_back(num,s[i]);
    int pos=index-3+1;
    Num* temp=searchNext(num,'.');
    std::cout << temp->c << std::endl;
    show(num);
}

int main(int argc, char const *argv[])
{
    // string s;
    // getline(cin,s);
    reShow("+1.23400E-03");
}