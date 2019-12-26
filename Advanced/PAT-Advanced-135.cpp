#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int id;
    int sum;
    int complish;
    int submits;
};
bool cmp(Node n1,Node n2){
    if(n1.sum==n2.sum && n1.complish==n2.complish) return n1.id<n2.id;
    if(n1.sum==n2.sum) return n1.complish>n2.complish;
    return n1.sum>n2.sum;
}
const int MAXN=10010;
int infos[MAXN][6];
void show(int rank,Node n,int k){
    printf("%d %05d %d",rank,n.id,n.sum);
    for (int i = 1; i <= k; i++){
        if(infos[n.id][i]==-2)
            printf(" -");
        else if(infos[n.id][i]==-1)
            printf(" 0");
        else
            printf(" %d",infos[n.id][i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[]){
    int n,k,m,id,num,sc;
    scanf("%d %d %d",&n,&k,&m);
    int fullmark[k+1];
    int sums[n+1]={0};
    for (int i = 1; i <= n; i++)
        fill(infos[i],infos[i]+6,-2);
    for (int i = 1; i <= k; i++)
        scanf("%d",&fullmark[i]);
    for (int i = 1; i <= m; i++){
        scanf("%05d %d %d",&id,&num,&sc);
        if(sc>=infos[id][num])
            infos[id][num]=sc;
    }
    Node nodes[n+1];
    vector<Node> v;
    for (int i = 1; i <= n; i++){
        nodes[i].id=i;
        nodes[i].sum=0;
        nodes[i].complish=0;
        nodes[i].submits=0;
        for (int j = 1; j <= k; j++){
            if(infos[i][j]>=0) {
                nodes[i].sum+=infos[i][j];
                nodes[i].submits++;
                if(infos[i][j]==fullmark[j])
                    nodes[i].complish++;
            }
        }
        if(nodes[i].submits>0)
            v.push_back(nodes[i]);
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=1,cur=1;
    show(cur,v[0],k);
    cnt++;
    for (int i = 1; i < v.size(); i++){
        if(v[i].sum!=v[i-1].sum)
            cur=cnt;
        show(cur,v[i],k);
        cnt++;
    }
    return 0;
}
