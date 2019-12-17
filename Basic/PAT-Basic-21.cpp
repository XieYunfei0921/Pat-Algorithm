#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAXN=10001;
int table[MAXN];
bool isPrim(int x){
    for (int i = 2; i <= sqrt(x); i++)
        if(x%i==0) return false;
    return true;
}
struct Prim{
    int val;
    int id;
    Prim nextPrim(){
        int temp=this->val+1;
        Prim p;
        while (true)
        {
            if(isPrim(temp)) {p.id=this->id+1;p.val=temp;break;}
            temp++;
        }
        delete(this);
        return p;
    }
};

void show(int start,int end){
    Prim first={2,1};    
    while (first.id <= end)
    {
        if(first.id >= start){
            if((first.id-start)%10==0) cout<<first.val<<"\n";
            else cout<<first.val<<" ";
        }
        first=first.nextPrim();
    }
}

void caculate(int num){
    int index=0;
    int start=2;
    while (index<num)
    {
        if(isPrim(start)){
            table[index]=start;
            index++;
        }
        start++;
    }
}

void showRange(int start,int end){
    int from=start-1;int to=end-1;
    for (int i = from; i <= to; i++)
    {
        if((i-from)%10==9) cout<<table[i]<<"\n";
        else if(i==to) cout<<table[i];
        else cout<<table[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{   
    int m,n;
    cin>>m>>n;
    caculate(n);
    showRange(m,n);
    return 0;
}
