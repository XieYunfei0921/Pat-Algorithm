#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
map<string,set<int> > titles;
map<string,set<int> > authors;
map<string,set<int> > keywords;
map<string,set<int> > publishs;
map<string,set<int> > years;
void setKeywords(string key,int id){
    vector<string> temp;
    int index=0;
    while (key.find(" ")!=string::npos){
        temp.push_back(key.substr(index,key.find(" ")-index));
        index=key.find(" ")+1;
        key=key.substr(index,key.length()-index+1);
    }
    temp.push_back(key);
    for (int i = 0; i < temp.size(); i++){
        keywords[temp[i]].insert(id);
    }
}
void search(string content){
    char ord=content[0];
    string val=content.substr(3,content.length()-2);
    cout<<content<<"\n";
    switch (ord)
    {
        case '1':{
            if(titles.count(val)==0) {cout<<"Not Found\n";return;}
            for (set<int>::iterator i = titles[val].begin(); i != titles[val].end(); i++)
                printf("%07d\n",*i);
        }
        break;
        case '2':{
            if(authors.count(val)==0) {cout<<"Not Found\n";return;}
            for (set<int>::iterator i = authors[val].begin(); i != authors[val].end(); i++)
                printf("%07d\n",*i);
        }
        break;
        case '3':{
            if(keywords.count(val)==0) {cout<<"Not Found\n";return;}
            for (set<int>::iterator i = keywords[val].begin(); i != keywords[val].end(); i++)
                printf("%07d\n",*i);
        }
        break;
        case '4':{
            if(publishs.count(val)==0) {cout<<"Not Found\n";return;}
            for (set<int>::iterator i = publishs[val].begin(); i != publishs[val].end(); i++)
                printf("%07d\n",*i);
        }
        break;
        case '5':{
            if(years.count(val)==0) {cout<<"Not Found\n";return;}
            for (set<int>::iterator i = years[val].begin(); i != years[val].end(); i++)
                printf("%07d\n",*i);
        }
        break;
    }
}
int main(int argc, char const *argv[]){
    int n,id;string title,author,keyword,publish,year;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d\n",&id);
        getline(cin,title);
        titles[title].insert(id);
        getline(cin,author);
        authors[author].insert(id);
        getline(cin,keyword);
        setKeywords(keyword,id);
        getline(cin,publish);
        publishs[publish].insert(id);
        getline(cin,year);
        years[year].insert(id);
    }
    int m;string content;
    scanf("%d",&m);
    cin.ignore();
    for (int i = 0; i < m; i++)
    {
        getline(cin,content);
        search(content);
    }
    return 0;
}
