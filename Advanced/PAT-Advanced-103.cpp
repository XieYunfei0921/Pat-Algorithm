#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
/*
TODO 数组越界： 问题出现在测试点4,这组数据的测试数据量较大
*/
struct Node{
    int id;
    int ge;
    int gi;
    float avg;
    void setAvg(){this->avg=(float)(this->ge+this->gi)/2;}
};
bool cmp(Node n1,Node n2){if(n1.avg==n2.avg) return n1.ge>n2.ge; return n1.avg>n2.avg;}
struct Info{
    int id;
    int ge;
    int gi;
    float avg;
    vector<int> list;
    void setAvg(){this->avg=(float)(this->ge+this->gi)/2;}
};
bool equal(Info n1,Info n2){return n1.avg==n2.avg && n1.ge==n2.ge;}
bool cmp2(Info i1,Info i2){if(i1.avg==i2.avg) return i1.ge>i2.ge;return i1.avg>i2.avg;}
int main(int argc, char const *argv[]){
    int n,m,k,ge,gi,ch;
    cin>>n>>m>>k;
    int quota[m];
    Node choices[m][n];
    Info list[n];
    for (int i = 0; i < m; i++)
        cin>>quota[i];
    for (int i = 0; i < n; i++){
        cin>>ge>>gi;
        list[i].id=i;
        list[i].ge=ge;
        list[i].gi=gi;
        list[i].setAvg();
        for (int j = 0; j < k; j++){
            cin>>ch;
            list[i].list.push_back(ch);
            Node temp={i,ge,gi,0};
            temp.setAvg();
            choices[ch][i]=temp;
        }
    }
    for (int i = 0; i < m; i++)
        sort(choices[i],choices[i]+n,cmp);
    sort(list,list+n,cmp2);
    set<int> ans[m];
    Info minInfo[m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < list[i].list.size(); j++){
            if(quota[list[i].list[j]]>0){
                ans[list[i].list[j]].insert(list[i].id);
                quota[list[i].list[j]]--;
                minInfo[list[i].list[j]]=list[i];
                break;
            }
            if(quota[list[i].list[j]]==0 && equal(list[i],minInfo[list[i].list[j]])){
                ans[list[i].list[j]].insert(list[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++){
        for (set<int>::iterator j = ans[i].begin(); j != ans[i].end(); j++){
            if(j!=ans[i].begin()) cout<<' ';
            cout<<*j;
        }
        cout<<"\n";
    }
    return 0;
}
