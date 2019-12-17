#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int matrix[10000][10000];bool state[10000][10000]={false};
int tempX=0,tempY=0;
void setLeft(int num){matrix[tempX][tempY-1]=num;state[tempX][tempY-1]=true;tempY--;}
void setRight(int num,int limit){matrix[tempX][tempY+1]=num;state[tempX][tempY+1]=true;tempY++;}
void setUp(int num){matrix[tempX-1][tempY]=num;state[tempX-1][tempY]=true;tempX--;}
void setDown(int num,int limit){matrix[tempX+1][tempY]=num;state[tempX+1][tempY]=true;tempX++;}
bool hasLeft(int ylimit){return tempY-1>=0 && state[tempX][tempY-1]==false;}
bool hasRight(int ylimit){return tempY+1<=ylimit && state[tempX][tempY+1]==false;}
bool hasUp(int xlimit){return tempX-1>=0 && state[tempX-1][tempY]==false;}
bool hasDown(int xlimit){return tempX+1<=xlimit && state[tempX+1][tempY]==false;}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int table[n];
    for (int i = 0; i < n; i++)
        cin>>table[i];
    sort(table,table+n);
    reverse(table,table+n);
    int x,y;
    for (int i = sqrt(n); i >=0; i--)
        if(n%i==0) {x=n/i;y=i;break;}
    int xlimit=x-1,ylimit=y-1;
    matrix[0][0]=table[0];state[0][0]=true;
    // 方向1 2 3 4 右下左上
    int direction=1;
    for (int i = 1; i < n; i++)
    {
        // 拐点设置
        // std::cout << "direction= "<<direction<<"\tpos= ("<<tempX<<","<<tempY<<")"<<"\tElement= "<<table[i]<<"\tStatus= "<<state[tempX][tempY] << std::endl;
        if(!hasRight(ylimit) && direction==1) {direction=2;setDown(table[i],ylimit);continue;}
        if(!hasDown(xlimit) && direction==2) {direction=3;setLeft(table[i]);continue;}
        if(!hasLeft(ylimit) && direction==3) {direction=4;setUp(table[i]);continue;}
        if(!hasUp(xlimit) && direction==4) {direction=1;setRight(table[i],ylimit);continue;}
        if(direction==1) {setRight(table[i],ylimit);continue;}
        if(direction==2) {setDown(table[i],xlimit);continue;}
        if(direction==3) {setLeft(table[i]);continue;}
        if(direction==4) {setUp(table[i]);continue;}
    }
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if(j!=y-1) cout<<matrix[i][j]<<" ";
            else cout<<matrix[i][j];
        }
        cout<<"\n";
    }
    

    return 0;
}
