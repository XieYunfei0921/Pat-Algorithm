#include <iostream>
#include <stack>
#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n + 1);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        
        int current = 1;
        for(int j = 1; j <= n; j++) {
            s.push(j);
            // 超出栈最大长度 跳出 s的内容 1 2 3 4 5 6 7...n
            if(s.size() > m) break;
            // 
            while(!s.empty() && s.top() == v[current]) {
                cout<<"cur= "<<v[current]<<"\ttop= "<<s.top()<<"\n";
                s.pop();
                current++;
            }
        }
        if(current == n + 1) flag = true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}