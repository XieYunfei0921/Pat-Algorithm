#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAXN=510;
const int INF=1000000000;
int d[MAXN],ts[MAXN];
bool vis[MAXN]={false}; 
vector<int> pre[MAXN];
vector<int> pret[MAXN];
int n,m,v1,v2,flag,len,timex,st,ed,spath,stimex;
struct Node{
	int id;
	int dis; 
	int timex;
};
map<int,Node> Adj[MAXN];
void dijkstraDis(int st){
	fill(d,d+MAXN,INF);
	d[st]=0;	
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(map<int,Node>::iterator i=Adj[u].begin();i!=Adj[u].end();i++){
			if(vis[i->first]==false && d[u]+i->second.dis<d[i->first]){
				d[i->first]=d[u]+i->second.dis;
				pre[i->first].clear();
				pre[i->first].push_back(u); 
			}else if(vis[i->first]==false && d[u]+i->second.dis==d[i->first]){
				pre[i->first].push_back(u);
			}			
		}
	}
}
void dijkstraTime(int st){
	fill(vis,vis+MAXN,false);
	fill(ts,ts+MAXN,INF);
	ts[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && ts[j]<MIN){
				u=j;
				MIN=ts[j];
			}
		}		
		if(u==-1) return;
		vis[u]=true;
		for(map<int,Node>::iterator i=Adj[u].begin();i!=Adj[u].end();i++){
			if(vis[i->first]==false && ts[u]+i->second.timex<ts[i->first]){
				ts[i->first]=ts[u]+i->second.timex;
				pret[i->first].clear();
				pret[i->first].push_back(u); 
			}else if(vis[i->first]==false && ts[u]+i->second.timex==ts[i->first]){
				pret[i->first].push_back(u);
			}			
		}
	}
}
vector<int> temp; 
vector<int> shortPath;
vector<int> shortTime;
int shortPathLen=INF;
int shortTimeLen=INF;
void DFSDistance(int start){
	if(start==st){
		temp.push_back(start);
		int tempval=0;
		for(int i=temp.size()-2;i>=0;i--)
			tempval+=Adj[temp[i+1]][temp[i]].timex;		
		if(tempval<shortPathLen){
			shortPathLen=tempval;
			shortPath=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(start); 
	for(int i=0;i<pre[start].size();i++) DFSDistance(pre[start][i]);
	temp.pop_back();
}
void DFSTime(int start){
	if(start==st){
		temp.push_back(start);
		if(temp.size()<shortTimeLen){
			shortTimeLen=temp.size();
			shortTime=temp;
		} 
		temp.pop_back();
		return;
	}
	temp.push_back(start);
	for(int i=0;i<pret[start].size();i++) DFSTime(pret[start][i]);
	temp.pop_back();
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d %d",&v1,&v2,&flag,&len,&timex);
		Adj[v1][v2]=Node{v2,len,timex};
		if(flag==0) Adj[v2][v1]=Node{v1,len,timex};
	}
	scanf("%d %d",&st,&ed);		
	dijkstraDis(st);
	dijkstraTime(st);
	DFSDistance(ed);
	DFSTime(ed);
	bool flag=true;
	if(shortTime.size()!=shortPath.size())
		flag=false;
	else{
		for(int i=0;i<shortPath.size();i++)
			if(shortTime[i]!=shortPath[i]){flag=false;break;}
	} 
	if(!flag){
		printf("Distance = %d: %d",d[ed],shortPath[shortPath.size()-1]);
		for(int i=shortPath.size()-2;i>=0;i--)
			printf(" -> %d",shortPath[i]);
		printf("\nTime = %d: %d",ts[ed],shortTime[shortTime.size()-1]);
		for(int i=shortTime.size()-2;i>=0;i--)
			printf(" -> %d",shortTime[i]);
	}else{
		printf("Distance = %d; ",d[ed]);
		printf("Time = %d: %d",ts[ed],shortTime[shortTime.size()-1]);
		for(int i=shortTime.size()-2;i>=0;i--) printf(" -> %d",shortTime[i]);
	}
	return 0;
} 
