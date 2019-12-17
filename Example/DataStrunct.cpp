#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

struct MyStack{
    // top最顶层元素
    int top;
    int* arr;
    MyStack(){
        this->top=-1;
        this->arr=NULL;
    }
    void clear(){
        this->top=-1;
    }
    int size(){
        return this->top+1;
    }
    bool empty(){
        if(this->top==-1) return true;
        else return false;
    }
    void push(int x){
        this->top++;
        if(this->top==0)
            this->arr=&x;
        else
            *(this->arr+this->top)=x;
        std::cout << "push end" << std::endl;
    }
    void pop(){
        if(this->top!=-1){
            this->top--;
        }
        else{
            std::cout << "Error: 空数组不能pop" << std::endl;
        }
    }
    int topElement(){
        return *(arr+this->top);
    }
}s;

struct MyQueue{
    int* arr;
    int front;
    int end;
    MyQueue()
    {
        this->arr=NULL;
        this->front=-1;
        this->end=-1;
    }
    void clear(){
        this->arr=NULL;
        this->front=this->end=-1;
    }
    bool empty(){
        if(this->front==-1 || this->end==-1) return true;
        else return false;
    }
    int size(){
        return this->end-this->front+1;
    }
    // 入队
    void push(int x){
        int x1=0;
        if(this->empty()){
            // 给野指针地址
            this->arr=&x;
            this->front=0;
            this->end=0;
        }
        else
        {   
            int deta=++this->end;
            *(this->arr+deta)=x;
            std::cout <<"Addr: "<< this->arr <<"\tValue= "<<*this->arr<<"\tAddr+deta= "<<this->arr+deta<<"\tDetaValue= "<<*(this->arr+deta)<< std::endl;
        }
    }
    // 出队 队首出队
    void pop(){
        if(this->front!=-1){
            this->front++;
        }
    }
    // 取队首
    int get_front(){
        if(this->empty())
            return -999;
        else{
            return *(this->arr+this->front);
        }
    }
    // 取队尾
    int get_end(){
        if(this->empty())
            return -999;
        else
            return *(this->arr+this->end);
    }

}q;

struct StaticList{
    int data;
    // 使用数组下标来表示指针的位置
    int index;
};

struct MyLinkList{
    // 数据域
    int data;
    // 指针域
    MyLinkList* next;
};
MyLinkList* create(int* arr,int len){
    MyLinkList *p,*pre,*head;
    head=new MyLinkList;
    head->next=NULL;
    pre=head;
    for (int i = 0; i < len; i++)
    {
        p=new MyLinkList;
        p->data=*(arr+i);
        pre->next=p;
        pre=p;
    }
    
    return head;
}

int search(MyLinkList* head,int x){
    int cnt=0;
    MyLinkList* p=head->next;
    while (p!=NULL)
    {
        if(p->data==x)
            cnt++;
        p=p->next;
    }
    return cnt;
}

void insert(int* head,int pos,int x){
    MyLinkList* p=head;
    // 移动到pos-1位置
    for (int i = 0; i < pos-1; i++)
    {
        p=p->next;
    }
    MyLinkList* e=new MyLinkList;
    e->data=x;
    e->next=p->next;
    p->next=e;
}
void del(MyLinkList* head,int x){
    MyLinkList* p=head->next;
    MyLinkList* pre=head->next;
    while (p!=null)
    {
        if (p->data==x)
        {
            pre->next=p->next;
            // 处理内存泄漏
            delete(p);
            // 重新建立新的连接
            p=pre->next;
        }else
        {
            p=p->next;
        }
        
        
    }
    
}

int main(int argc, char const *argv[])
{
    // s.push(2);
    // s.push(4);
    // s.push(5);
    // std::cout << s.topElement()<< std::endl;
    // s.pop();
    // std::cout << s.topElement()<< std::endl;
    // q.push(1);
    // q.push(4);
    // q.push(8);
    // std::cout <<"Front= "<<q.get_front()<<"\tEnd= "<<q.get_end() << std::endl;
    // q.push(7);
    // std::cout <<"Front= "<<q.get_front()<<"\tEnd= "<<q.get_end() << std::endl;
    
    // C++ 解决内存泄漏的问题
    // delete(link1);

    // 创建链表
    int a[5]={1,7,2,3,4};
    MyLinkList* m=create(a,5);
    return 0;
}
