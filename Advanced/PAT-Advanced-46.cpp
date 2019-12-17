#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int identy[101]={0};
bool status[101]={false};
struct Node{
    int start;
    int end;
    void show(){
        std::cout << this->start<<" "<<this->end << std::endl;
    }
};
bool cmp(Node n1,Node n2){
    if(n1.start==n2.start) return n1.end<n2.end;
    return n1.start<n2.start;
}
void reset(){
    fill(identy,identy+101,0);
    fill(status,status+101,false);
}
bool parser(string s,bool flag){
    int val=s[0]=='+'?1:-1;
    int num=0;
    for (int i = 1; i < s.length(); i++)
        num=num*10+s[i]-'0';
    num=num-1;
    int prg=identy[num];
    identy[num]=flag?-val:val;
    return identy[num]*prg>=0;
}
int main(int argc, char const *argv[])
{
    int n;bool flag=true;
    vector<string> v;
    string temp;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    vector<Node> res;
    int wolf[2];
    for (int i = 0; i < n; i++)
    {   
        int cnt=0;
        for (int j = i+1; j < n; j++)
        {   
            flag=true;
            int totalW=0;
            status[i]=true;status[j]=true;
            for (int k = 0; k < n; k++)
                flag*=parser(v[k],status[k]);
            for (int k = 0; k < n; k++){
                if(identy[k]==-1) totalW++;
                if(totalW>2) {flag=false;break;}
            }
            if(flag){
                int x=totalW;
                for (int k = 0; k < n; k++)
                {
                    if(identy[k]==0){
                        if(x<2){
                            identy[k]=-1;
                            x++;
                        }
                        else
                            identy[k]=1;
                    } 
                }
                if(identy[i]*identy[j] == -1 && x==2){
                    for (int k = 0; k < n; k++){
                        if(identy[k]==-1){
                            wolf[2-x]=k+1;
                            x--;
                        }
                    }
                    res.push_back(Node{wolf[0],wolf[1]});
                }
                reset();
            }
            else
                reset();
        }
    }
    if(res.size()!=0){
        sort(res.begin(),res.end(),cmp);
        res[0].show();
    }
    else
        std::cout << "No Solution" << std::endl;
    return 0;
}
