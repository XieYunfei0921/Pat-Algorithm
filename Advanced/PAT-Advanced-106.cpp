#include <cstdio>
#include <set>
using namespace std;
int main(int argc, char const *argv[]){
    int n,m,nc,nt,ele,k,c,t;
    scanf("%d",&n);
    set<int> s[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&m);
        for (int j = 0; j < m; j++){
            scanf("%d",&ele);
            s[i].insert(ele);
        }
    }
    scanf("%d",&k);
    for (int i = 0; i < k; i++){
        scanf("%d %d",&c,&t);
        if(s[c-1].size()<s[t-1].size()) swap(c,t);
        int cnt=0;
        for (set<int>::iterator j =s[t-1].begin(); j != s[t-1].end(); j++)
            if(s[c-1].count(*j)!=0)
                cnt++;
        printf("%.1f%%\n",(float)cnt/((s[c-1].size()+s[t-1].size())-cnt)*100);
    }
    return 0;
}
