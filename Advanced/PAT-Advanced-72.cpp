#include <iostream>
#include <algorithm>
using namespace std;
int arr[100],pos[100],heap[101];int n;
bool insertStep(int n,int k){
    // 假设前k个元素有序,即0-k-1是有序的
    bool flag=true;
    int temp=arr[k];
    int tag=true;
    for (int i = k-1; i >= 0; i--){
        if(arr[i]>temp){
            if(k==1){
                arr[1]=arr[0];
                arr[0]=temp;
                continue;
            } 
            arr[i+1]=arr[i];
        }
        else{
            arr[i+1]=temp;
            tag=false;
            break;
        }
    }
    if(tag) arr[0]=temp;
    for (int i = 0; i < n; i++)
        if(pos[i]!=arr[i]) flag=false;
    return flag;
}
void downSize(int start,int finish){
    int l=start;int j=2*l;
    // 调节完成后堆顶是最大的元素
    while (j<=finish)
    {
        if(j+1<=finish && heap[j+1]>heap[j])
            j=j+1;
        if(heap[j]>heap[l]){
            swap(heap[j],heap[l]);
            l=j;
            j=l*2;
        }else{
            break;
        }
    }
}
// low为1
bool downAdjust(int start,int time,bool vis){
    int finish=n-time+1;
    bool flag=true;
    int l=start;int j=2*l;
    while (j<=finish)
    {
        if(j+1<=finish && heap[j+1]>heap[j])
            j=j+1;
        if(heap[j]>heap[l]){
            swap(heap[j],heap[l]);
            l=j;
            j=l*2;
        }else{
            break;
        }
    }
    for (int i = 0; i < n; i++)
        if(heap[i+1]!=pos[i]) flag=false;
    if(vis)
        swap(heap[1],heap[n-time+1]);
    return flag;
}

// 倒叙遍历 保证堆顶元素最大
void createHeap(){
    for (int i = n/2; i >= 1; i--)
        downSize(i,n);
}
int main(int argc, char const *argv[])
{
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
        heap[i+1]=arr[i];
    }
    for (int i = 0; i < n; i++)
        cin>>pos[i];
    int index=-1;
    bool f1=false;
    for (int i = 1; i < n; i++){
        if(insertStep(n,i)){
            std::cout << "Insertion Sort" << std::endl;
            f1=true;
            index=i;
            break;
        }
    }
    if(f1){
        insertStep(n,index+1);
        cout<<arr[0];
        for (int i = 1; i < n; i++)
            cout<<" "<<arr[i];
    }
    createHeap();
    bool f2=false;
    for (int i = 1; i < n; i++){
        if(downAdjust(1,i,true)){
            std::cout << "Heap Sort" << std::endl;
            f2=true;
            index=i;
            break;
        }
    }
    if(f2){
        downAdjust(1,++index,false);
        cout<<heap[1];
        for (int i = 2; i <= n ; i++)
            cout<<" "<<heap[i];
    }
    return 0;
}
