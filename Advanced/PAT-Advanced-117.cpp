#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int lover[100000];
int main(int argc, char const *argv[]){
    int n,k,l1,l2,x;
    fill(lover,lover+100000,-1);
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%05d %05d",&l1,&l2);
        lover[l1]=l2;
        lover[l2]=l1;
    }
    set<int> s,ans;
    scanf("%d",&k);
    for (int i = 0; i <k ; i++){
        scanf("%05d",&x);
        if(lover[x]!=-1)
            s.insert(x);
        else
            ans.insert(x);
    }
    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
        if(s.count(lover[*i])==0)
            ans.insert(*i);
    printf("%d\n",ans.size());
    for(set<int>::iterator i=ans.begin();i!=ans.end();i++){
        if(i!=ans.begin()) printf(" ");
        printf("%05d",*i);
    }
    return 0;
}
