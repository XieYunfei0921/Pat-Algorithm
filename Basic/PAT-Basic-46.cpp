#include <cstdio>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,gid,uid,s;
    scanf("%d",&n);
    map<int,int> score;
    for (int i = 0; i < n; i++)
    {   
        scanf("%d-%d %d",&gid,&uid,&s);
        score[gid]+=s;
    }
    int group=0,scores=0;
    for (map<int,int>::iterator i = score.begin(); i != score.end(); i++)
        if(i->second>scores){scores=i->second;group=i->first;}
    printf("%d %d",group,scores);
    return 0;
}
