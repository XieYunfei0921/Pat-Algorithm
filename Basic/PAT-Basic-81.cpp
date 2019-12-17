#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,d;double e;
    cin>>n>>e>>d;
    int cntP=0,cntK=0;
    for (int i = 0; i < n; i++)
    {
        int days;
        cin>>days;
        int cnt=0;
        vector<double> vd;
        for (int i = 0; i < days; i++)
        {  
            double val;
            cin>>val;
            vd.push_back(val);
        }
        for (int i = 0; i < vd.size(); i++)
            if(vd[i]<e) {cnt++;}
        if(cnt*2>days){
            cntP++;
            if(days>d)
                cntK++;
        }
        vd.clear();
    }
    printf("%.1f%% %.1f%%",(double)(cntP-cntK)/(double)n*100,(double)cntK/(double)n*100);
    return 0;
}
