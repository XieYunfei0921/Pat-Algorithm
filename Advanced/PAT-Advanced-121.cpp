#include <cstdio>
#include <vector>
using namespace std;
int nexval[100010];
// 设值前驱数组支持向前查找的随机存取,这样就不用借助vector
int lastval[100010];
int ele[100010];
vector<int> v;
int main(int argc, char const *argv[]){
    int org,n,k,cur,nx,val;
    scanf("%05d %d %d",&org,&n,&k);
    for (int i = 0; i < n; i++){
        scanf("%05d %d %05d",&cur,&val,&nx);
        ele[cur]=val;
        nexval[cur]=nx;
        lastval[nx]=cur;
    }
    int last=100007,temp=0,x=org;
    while(x!=-1){
        temp++;
        x=nexval[x];
    }
    while (temp>0){
        if(temp>=k){
            int cnt=0;
            while (cnt<k && org!=-1){
                v.push_back(org);
                org=nexval[org];
                cnt++;
            }
            nexval[last]=v[k-1];
            if(temp==k) nexval[v[0]]=-1;
            for (int i = k-1; i >0; i--)
                nexval[v[i]]=v[i-1];
            last=v[0];
            v.clear();
            temp-=k;
        }else{
            nexval[last]=org;
            temp=0;
        }
    }
    int start=nexval[100007];
    while (start!=-1){
        if(nexval[start]!=-1)
            printf("%05d %d %05d\n",start,ele[start],nexval[start]);
        else
            printf("%05d %d %d\n",start,ele[start],nexval[start]);
        start=nexval[start];
    }
    return 0;
}
