#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]){
    int n,m,x;
    vector<int> fp,fn,pp,pn;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&x);
        if(x>0) fp.push_back(x);
        else fn.push_back(x);
    }
    scanf("%d",&m);
    for (int i = 0; i < m; i++){
        scanf("%d",&x);
        if(x>0) pp.push_back(x);
        else pn.push_back(x);
    }
    sort(fn.begin(),fn.end());
    sort(pn.begin(),pn.end());
    sort(fp.begin(),fp.end());
    reverse(fp.begin(),fp.end());
    sort(pp.begin(),pp.end());
    reverse(pp.begin(),pp.end());
    int maxn=0;
    for (int i = 0; i < min(fp.size(),pp.size()); i++)
        maxn+=fp[i]*pp[i];
    for (int i = 0; i < min(fn.size(),pn.size()); i++)
        maxn+=fn[i]*pn[i];
    printf("%d",maxn);
    return 0;
}
