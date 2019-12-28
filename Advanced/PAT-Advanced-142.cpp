    #include <iostream>
    #include <algorithm>
    using namespace std;
    const int MAX_SIZE=100010;
    const int Undefined=100010;
    /*
        不使用树状数组容易TLE
    */
    int toInt(string s){
        int num=0;
        for (int i = 0; i < s.length(); i++)
            num=10*num+s[i]-'0';
        return num;
    }
    struct myStack{
        int point;
        int arr[MAX_SIZE];
        int temp[MAX_SIZE];
        void push(int x){
            this->point++;
            arr[this->point]=x;
        }
        void pop(){
            if(this->point<0) {cout<<"Invalid\n";return;}
            int temp=arr[this->point];
            cout<<temp<<"\n";
            arr[this->point]=Undefined;
            this->point--;
        }
        void peekMedian(){
            if(this->point<0) {cout<<"Invalid\n";return;}
            for (int i = 0; i <= this->point; i++)
                temp[i]=arr[i];
            sort(temp,temp+this->point+1);
            int mid=this->point%2==0?this->point/2:(this->point+1)/2;
            cout<<temp[mid]<<"\n";
        }
    }s;
    int main(int argc, char const *argv[]){
        int n;string st;
        cin>>n;
        s.point=-1;
        cin.ignore();
        for (int i = 0; i < n; i++){
            getline(cin,st);
            if(st=="Pop")
                s.pop();
            else if(st=="PeekMedian")
                s.peekMedian();
            else{
                string t=st.substr(st.find(" ")+1,st.length()-st.find(" "));
                s.push(toInt(t));
            }
        }
        return 0;
    }
