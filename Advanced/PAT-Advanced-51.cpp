#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
int toDecibal(string s){
    return ((s[0]-'0')*10+(s[1]-'0'))*3600+((s[3]-'0')*10+(s[4]-'0'))*60+((s[6]-'0')*10+(s[7]-'0'));
}
int main(int argc, char const *argv[])
{
    int n,k,pro,cnt=0,sum=0;
    cin>>n>>k;
    string s;
    map<int,int> mp;
    int window[k];
    fill(window,window+k,toDecibal("08:00:00"));
    for (int i = 0; i < n; i++)
    {
        cin>>s>>pro;
        if(s>="17:00:01") continue;
        mp[toDecibal(s)]=pro;
        cnt++;
    }
    for (map<int,int>::iterator i = mp.begin(); i != mp.end(); i++){
        int start;
        if(i->first<=toDecibal("08:00:00")){
            sum+=toDecibal("08:00:00")-i->first;
            start=toDecibal("08:00:00");
        }
        else
            start=i->first;
        int mintime=100000,index=-1;bool flag=false;
        for (int j = 0; j < k; j++)
        {
            if(window[j]<=start){
                flag=true;
                window[j]=start+i->second*60;
                break;
            }
            else
            {
                if(window[j]<mintime){
                    index=j;
                    mintime=window[j];
                }
            }
        }
        if(flag) continue;
        else {
            sum+=mintime-start;
            window[index]+=i->second*60;
        }
    }
    printf("%.1f",(double)sum/(60*cnt));
    return 0;
}
