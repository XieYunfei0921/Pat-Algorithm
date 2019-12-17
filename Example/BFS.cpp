#include <iostream>
#include <math.h>
#include <queue>
#include <algorithm>
using namespace std;

struct Point{
    int x;
    int y;
    int val;
    int part=-1;
    bool flag=false;
    bool isUsed(){
        return this->flag;
    }
    bool setFlag(bool flag){
        this->flag=flag;
    }
    int getPart(){
        return this->part;
    }
    void setPart(int part){
        this->part=part;
    }
}ps[42];

Point left(Point* ps,Point s){
    return find(ps,s.x-1,s.y);
}
Point right(Point* ps,Point s){
    return find(ps,s.x+1,s.y);  
}
Point up(Point* ps,Point s){
    return find(ps,s.x,s.y-1);
}
Point down(Point* ps,Point s){
    return find(ps,s.x,s.y+1);
}
Point find(Point* ps,int x,int y){
    return ps+(y-1)*7+x;
}

bool checkPoint(Point* ps,Point s){
    Point down=down(ps,s);
    Point up=up(ps,s);
    Point left=left(ps,s);
    Point right=right(ps,s);
    if (down.val==1 && up.val==1 && left.val==1 && right.val==1)
    {
        return true;
    }else
    {
        return false;
    }
    
}

queue<Point> q;
void addPoints(Point* matrix,int len){
    if(len==0)
        return;
    if(matrix->val==1){
        q.push(*matrix);
    }
    addPoints(matrix+1,len-1);
}
int BFS(Point* ps,int XMAX,int YMAX){
    int cnt=0;
    int part=0;
    while (!q.empty())
    {
        Point s=q.front();
        std::cout << "s= "<<s.x<<", "<<s.y << std::endl;
        if (s.part==-1)
        {
            s.part=part;
        }
        if(left(ps,s).x<0 || down(ps,s).y>YMAX || up(ps,s).y<0 || right(ps,s).x>XMAX || s.val!=1){
           std::cout << "出界s= ("<<s.x<<","<<s.y<<")" << std::endl;
           q.pop();
            continue;
        }else if(!checkPoint(ps,s)){
            std::cout << "不符合包围条件s= ("<<s.x<<","<<s.y<<")"<< std::endl;
            q.pop();
            continue;
        }
        else
        {   
            std::cout << "符合的s= ("<<s.x<<","<<s.y<<")" << std::endl;
            left(ps,s).setPart(s.part);
            right(ps,s).setPart(s.part);
            up(ps,s).setPart(s.part);
            down(ps,s).setPart(s.part);
            q.push(left(ps,s));
            q.push(right(ps,s));
            q.push(up(ps,s));
            q.push(down(ps,s));
            q.pop();
            part++;
        }
    }
    return part;
}
int main(int argc, char const *argv[])
{   
    int arr[6][7]={
        {0,1,1,1,0,0,1},
        {0,0,1,0,0,0,0},
        {0,0,0,0,1,0,0},
        {0,0,0,1,1,1,0},
        {1,1,1,0,1,0,0},
        {1,1,1,1,0,0,0}
    };
    int index=0;
    int MaxX=7,MaxY=6;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {   
            ps[7*i+j].x=j;
            ps[7*i+j].y=i;
            ps[7*i+j].val=arr[i][j];
        }
    }
    addPoints(ps,42);
    std::cout << "Size= "<<q.size() << std::endl;
    int num=BFS(ps,MaxX,MaxY);
    std::cout << "Num= "<<num << std::endl;
    return 0;
}
