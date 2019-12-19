#include <iostream>
using namespace std;
int main(int argc, char const *argv[]){
    int n;
    string dict[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string unit[4]={"","Shi","Bai","Qian"};
    string sign="Fu";
    cin>>n;
    if(n==0){
        cout<<"ling";
        return 0;
    }
    string ans="";
    if(n<0) {
        ans+=sign;
        n=-n;
    }
    if(n/100000000!=0){
        ans+=" "+dict[n/100000000]+" Yi";
        n-=n/100000000*100000000;
    }
    if(n/10000!=0){
        int temp=n/10000;
        int arr[4]={0};int p=0;
        while (temp>0){
            arr[p]=temp%10;
            temp/=10;
            p++;
        }
        p=3;
        int haszero=1;
        while (p>=0){
            if(arr[p]!=0 && haszero==3)
                ans+=" ling "+dict[arr[p]]+" "+unit[p];
            else if(arr[p]!=0 && haszero==1){
                haszero++;
                ans+=" "+dict[arr[p]]+" "+unit[p]; 
            }else if(haszero==2 && arr[p]==0)
                haszero++;
            p--;
        }
        if(n/10000!=0){
            if(arr[0]==0) ans+=" ";
            ans+="Wan";
        } 
        n-=n/10000*10000;
    }
    int arr[4]={0};int p=0;
    string temp="";
    if(n!=0){
        while (n>0){
            arr[p]=n%10;
            n/=10;
            p++;
        }
        p=3;
        bool haszero=false;
        while (p>=0){
            if(arr[p]!=0 && haszero)
                temp+=" ling "+dict[arr[p]]+" "+unit[p];
            else if(arr[p]!=0 && !haszero)
                temp+=" "+dict[arr[p]]+" "+unit[p]; 
            else
                haszero=true;
            p--;
        }
    }
    ans+=temp;
    if(ans[0]==' ') ans=ans.substr(1,ans.length()-1);
    cout<<ans;
    return 0;
}
