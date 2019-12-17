#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
float coefficient[2001]={0};
struct Node{
    int exp;
    float coe;
};
int main(int argc, char const *argv[])
{   
    fill(coefficient,coefficient+2001,0);
    int k1,k2,exp;float coe;
    scanf("%d",&k1);
    vector<Node> v;
    for (int i = 0; i < k1; i++)
    {
        scanf("%d %f",&exp,&coe);
        v.push_back(Node{exp,coe});
    }
    scanf("%d",&k2);
    for (int i = 0; i < k2; i++)
    {
        scanf("%d %f",&exp,&coe);
        for (int i = 0; i < v.size(); i++){
            coefficient[v[i].exp+exp]+=v[i].coe*coe;
        }
    }
    int cnt=0;
    for (int i = 0; i < 2001; i++)
        if(coefficient[i]!=0.0) cnt++;
    printf("%d",cnt);
    for (int i = 2001; i >=0; i--)
        if(coefficient[i]!=0.0){
            printf(" %d %.1f",i,coefficient[i]);
        } 
    return 0;
}
