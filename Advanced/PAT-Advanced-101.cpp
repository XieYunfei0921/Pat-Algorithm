#include <iostream>
#include <cstdio>
#include <string.h>
#include <set>
using namespace std;
/*
    第四个测试点TLE
*/
int main(int argc, char const *argv[]){
    int n,k,c,cs;string id,temp;
    scanf("%d %d",&n,&k);
    set<string> arr[k+1];
    for (int i = 0; i < n; i++){
        cin>>id>>c;
        for (int j = 0; j < c; j++){
            scanf("%d",&cs);
            arr[cs].insert(id);
        }
    }
    for (int i = 1; i <= k; i++){
        printf("%d %d\n",i,arr[i].size());
        for (set<string>::iterator j = arr[i].begin(); j != arr[i].end(); j++)
            cout<<*j<<"\n";
    }
    return 0;
}
