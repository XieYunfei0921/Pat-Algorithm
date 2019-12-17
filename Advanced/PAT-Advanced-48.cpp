#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    string id;
    int score;
    int fr;
    int area;
    int ar;
    void show(){
        std::cout << this->id<<" "<<this->fr<<" "<<this->area<<" "<<this->ar << std::endl;
    }
};
bool cmp(Node n1,Node n2){
    if(n1.score==n2.score) return n1.id<n2.id;
    return n1.score>n2.score;
}
int main(int argc, char const *argv[])
{
    int n,k,sc;
    string id;
    cin>>n;
    vector<Node> v,ans;
    int start=0,finish=0;
    for (int i = 0; i < n; i++)
    {
        cin>>k;
        finish=start+k;
        for (int j = 0; j < k; j++)
        {
            cin>>id>>sc;
            v.push_back(Node{id,sc,0,i+1,0});
        }
        sort(v.begin(),v.end(),cmp);
        v[0].ar=1;
        ans.push_back(v[0]);
        int cnt=2;
        for (int j = 1; j < v.size(); j++)
        {
            if(v[j].score==v[j-1].score){
                v[j].ar=v[j-1].ar;
            }else
            {
                v[j].ar=cnt;
            }
            cnt++;
            ans.push_back(v[j]);
        }
        v.clear();
    }
    std::cout << ans.size() << std::endl;
    sort(ans.begin(),ans.end(),cmp);
    ans[0].fr=1;
    int rank=2;
    for (int i = 1; i < ans.size(); i++)
    {
        if(ans[i].score==ans[i-1].score){
            ans[i].fr=ans[i-1].fr;
        }else{
            ans[i].fr=rank;
        }
        rank++; 
    }
    for (int i = 0; i < ans.size(); i++)
        ans[i].show();
    return 0;
}
